/*
* TCS34725.h
*
* Created: 08/10/2017 12:37:23
* Author: SoftwareEngineer
*/


#ifndef __TCS34725Helper_H__
#define __TCS34725Helper_H__
#include "Exceptions.h"
 #include <stdint.h>
class TCS34725Helper
{
	public:
	typedef struct Wait{
		public:
		char time;
		bool isLong;
		Wait(char time, bool isLong):time(time), isLong(isLong){}
	};
	static unsigned char GetATime(uint16_t milliseconds);
	static unsigned char GetAGain(char gain);
	static Wait CalculatWait(uint16_t desired_ma, unsigned char aTime);
	protected:
	private:
};

#endif