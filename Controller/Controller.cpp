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
#include "LM75.h"
#include "UART.h"
#include "Stopwatch.h"
#include "Settings.h"
#include "Leds.h"
#include "Endpoint.h"
#include "Temperatures.h"
#include "i2cmaster.h"
#include "TC654.h"
#include "Fans.h"
#include "SystemCheck.h"
using namespace std;
int main(void)
{
	wdt_disable();
	i2c_init();
	Outputs::Initialize();
	//Stopwatch stopWatch = Stopwatch();
	UART& uart = UART::GetInstance();
	Settings& settings=Settings::GetInstance();
	TC654 tc654 = TC654(0x01, 0x01);
	IGetFanInfo* iGetFanInfos[]={tc654.GetIGetFan1Info(), tc654.GetIGetFan2Info()};
	Fans& fans = Fans::GetInstance();
	fans.SetInterfaces(iGetFanInfos, 0x02, &settings);
	LM75* lm75_7= new LM75(0x07, "lm75_7");
	LM75* lm75_6= new LM75(0x06, "lm75_6");
	IGetTemperatureInfo* lm75s[] = {lm75_7, lm75_6};
	Temperatures& temperatures=Temperatures::GetInstance();
	temperatures.SetInterfaces(lm75s, 0x2);
	SystemCheck& systemCheck = SystemCheck::GetInstance();
	systemCheck.SetInterfaces(&temperatures, &settings, &fans);
	Leds::Main::SetGreen();		
	Endpoint* endpoint = new Endpoint(&uart, &uart, &settings, &settings, &settings, &settings, &temperatures, &systemCheck);
	while(1)
	{
	    endpoint->Run();
	}
}