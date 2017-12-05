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
#include "Outputs.h"
#include "LM75.h"
#include "UART.h"
#include "Stopwatch.h"
#include "Settings.h"
#include "Leds.h"
#include "Endpoint.h"
#include "Temperatures.h"
#include "i2cmaster.h"
using namespace std;
int main(void)
{
	wdt_disable();
	i2c_init();
	Outputs::Initialize();
	//Stopwatch stopWatch = Stopwatch();
	UART& uart = UART::GetInstance();
	Settings& settings=Settings::GetInstance();
	LM75* lm75_7= new LM75(0x07, "lm75_7");
	LM75* lm75_6= new LM75(0x06, "lm75_6");
	IGetTemperatureInfo* lm75s[] = {lm75_7, lm75_6};
	Temperatures& temperatures=Temperatures::GetInstance();
	temperatures.SetInterfaces(lm75s, 0x2);
	Leds::Main::SetGreen();		
	Endpoint* endpoint = new Endpoint(&uart, &uart, &settings, &settings, &settings, &settings, &temperatures);
	while(1)
	{
	    endpoint->Run();
	}
}