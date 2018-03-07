/*
* Stopwatch.cpp
*
* Created: 08/10/2017 16:33:17
* Author: SoftwareEngineer
*/


#include "Stopwatch.h"
#include "Ticker.h"
long Stopwatch::msSinceTimerStart=0;
Stopwatch::Stopwatch()
{
	static bool initialized=false;
	if(!initialized){
		Ticker::Add(Stopwatch::Tick, TenMillisecond);
		initialized=true;
	}
	startMs=msSinceTimerStart;
}
void Stopwatch::Tick(){
	Stopwatch::msSinceTimerStart+=10;
}
Stopwatch::~Stopwatch()
{
}
long Stopwatch::GetMs()
{
	return msSinceTimerStart-this->startMs;
}
void Stopwatch::Reset()
{
	startMs=msSinceTimerStart;
}


/*
* countdownTimer.c
*
* Created: 23/03/2015 12:48:00
*  Author: EngineeringStdnt0001
*/