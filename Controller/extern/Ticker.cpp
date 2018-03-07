/*
* Ticker.cpp
*
* Created: 08/10/2017 19:13:26
* Author: SoftwareEngineer
*/


#include <avr/interrupt.h>
#include "Ticker.h"
#include "new.h"
#include "Uart.h"
#define CLOCK_SPEED (800000UL)
volatile volatile_vector< Ticker::Callback>Ticker::tickerCallbacksMilliseconds;
volatile volatile_vector< Ticker::Callback>Ticker::tickerCallbacksSeconds;
void Ticker::Add(Ticker::Callback  callback, TickerDelay tickerDelay){
	static bool initialized=false;
	if(!initialized){
		//http://www.arduinoslovakia.eu/application/timer-calculator
		TCCR0A = 0;
		TCCR0B = 0;
		TCNT0 = 0;

		// 100.16025641025641 Hz (8000000/((77+1)*1024))
		OCR0A = 77;
		// CTC
		TCCR0A |= (1 << WGM01);
		// Prescaler 1024
		TCCR0B |= (1 << CS02) | (1 << CS00);
		// Output Compare Match A Interrupt Enable
		TIMSK0 |= (1 << OCIE0A);
		sei();
		initialized=true;
	}
	if(tickerDelay==TenMillisecond){
		if(!Ticker::tickerCallbacksMilliseconds.contains(callback)){
		Ticker::tickerCallbacksMilliseconds.push_back(callback);}
	}
	else
	if(!Ticker::tickerCallbacksSeconds.contains(callback))tickerCallbacksSeconds.push_back(callback);
}
ISR(TIMER0_COMPA_vect)
{
	cli();
	for(int i=0; i<Ticker::tickerCallbacksMilliseconds.size(); i++)
	{
		Ticker::tickerCallbacksMilliseconds[i]();
	}
	sei();
}
