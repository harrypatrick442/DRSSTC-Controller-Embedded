/*
* TC654.cpp
*
* Created: 08/10/2017 12:37:23
* Author: SoftwareEngineer
*/
#include "i2cmaster.h"
#include "TCS34725.h"
#include "CommunicationException.h"
#include "TCS34725Helper.h"
unsigned char TCS34725Helper::GetATime(uint16_t milliseconds){
	uint16_t m=(milliseconds* 10)/24;
	if(m>0xff)
	m=0xff;
	return (char)m;
}
unsigned char TCS34725Helper::GetAGain(char gain){
	switch(gain)
	{

	case 1:
	return 0x00;
	case 4:
	return 0x01;
	case 16:
	return 0x02;
	default:
	return 0x03;
	}
}
TCS34725Helper::Wait TCS34725Helper::CalculatWait(uint16_t desired_ua, unsigned char aTime)
{
	uint32_t w =(((((uint32_t)(aTime)+1) *  564)-((((uint32_t)desired_ua)*24*(((uint32_t)aTime)+1))/10))/(((uint32_t)desired_ua) - 65 ));
	char wtime;
	bool wlong=false;
	if(w>614)
	{ 
		wtime=(w*10)/288;
		wlong=true;
	}
	else
		wtime = (w*10)/24;
	if(wtime>0xff)
		wtime=0xff;
	return Wait( (char) wtime, wlong);
}
