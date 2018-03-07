/*
* Controller.cpp
*
* Created: 07/10/2017 01:01:45
*  Author: SoftwareEngineer
*/


#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include "Outputs.h"
#include "UART.h"
#include "Stopwatch.h"
#include "Settings.h"
#include "Leds.h"
#include "Endpoint.h"
#include "i2cmaster.h"
#include "SystemCheck.h"
#include "TCS34725.h"
#include "ColourSensorTCS34725.h"
#include "IColourSensor.h"
#include "TCS34725Helper.h"
#include "SubscriptionRunner.h"
#include "Sender.h"
#include "ITests.h"
#include "IGetRGBC.h"
#include <avr/pgmspace.h>
#ifdef DEBUG
#include "Tests.h"
#else
#include "NoTests.h"
#endif
#define DESIRED_CURRENT_MA 200
#define PERSISTENCE 3
#define DESIRED_GAIN 1
#define ATIME_MILLISECONDS 10
int main(void)
{
	wdt_disable();
	i2c_init();
	Outputs::Initialize();
	Leds& leds = Leds::GetInstance();
	Stopwatch stopWatch = Stopwatch();
	UART& uart = UART::GetInstance();
	leds.GetBacklight()->TurnOn();
	leds.GetMain()->TurnOff();
	//Settings& settings=Settings::GetInstance();
	char aTime = TCS34725Helper::GetATime(ATIME_MILLISECONDS);
	char aGain = TCS34725Helper::GetAGain(DESIRED_GAIN);
	TCS34725Helper::Wait wait = TCS34725Helper::CalculatWait(DESIRED_CURRENT_MA, aTime);
	TCS34725* tcs34725 = new TCS34725("TCS34725", /*aTime*/ aTime,  /*wTime*/wait.time,   /*wLong*/wait.isLong,  /*aGain*/aGain,  /*aPers*/PERSISTENCE);
	Sender sender(&uart);
	SubscriptionRunner subscriptionRunner;
	ColourSensorTCS34725 colourSensor34725(tcs34725, &sender, &subscriptionRunner, leds.GetBacklight());
	SystemCheck& systemCheck = SystemCheck::GetInstance();
	//systemCheck.SetInterfaces(&settings);
	ITests* iTests =
	#ifdef DEBUG
	new Tests((ISendMessage*)&uart, (IGetRGBC*)tcs34725);
	#else
	new NoTests();
	#endif
	Endpoint* endpoint = new Endpoint(&uart, &uart, &sender, &colourSensor34725, &colourSensor34725, &systemCheck, iTests);
	bool on=false;
	while(1)
	{
		if(stopWatch.GetMs()>1000)
		{
			stopWatch.Reset();
			on=!on;
			if(on)
			leds.GetMain()->TurnOn();
			else
			leds.GetMain()->TurnOff();
		}
		endpoint->Run();
		subscriptionRunner.Run();
	}
}