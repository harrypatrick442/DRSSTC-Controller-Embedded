/*
* Ticker.h
*
* Created: 08/10/2017 19:13:27
* Author: SoftwareEngineer
*/

#ifndef __TICKER_H__
#define __TICKER_H__

#include <iterator>
#include <algorithm>
#include "volatile_vector.h"
#define CLOCK_SPEED (8000000UL)
enum TickerDelay{ Second=0, TenMillisecond=1} ;
class Ticker
{
	//variables
	public:
	
	typedef void (*Callback)(void);
	static volatile volatile_vector<Ticker::Callback>tickerCallbacksMilliseconds;
	static volatile volatile_vector<Ticker::Callback>tickerCallbacksSeconds;
	protected:
	private:
	//functions
	public:
	static void Add(Callback callback, TickerDelay tickerDelay);
	protected:
	private:

}; //Ticker

#endif //__TICKER_H__
