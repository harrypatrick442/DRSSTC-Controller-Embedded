/*
* Fans.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#define MAX_NUMBER_EXCEPTIONS 10
#include "Fans.h"
#include "FanSpeedException.h"
#include "CommunicationException.h"
#include "Exceptions.h"
#include "UART.h"

Fans Fans:: _Singleton;
Fans& Fans::GetInstance(){
	static bool initialized=false;
	if(!initialized)
	{
		initialized=true;
	}
	return _Singleton;
}
 void Fans::SetInterfaces(IGetFanInfo** iGetFanInfos, unsigned char nIGetFanInfos, IGetFanSpeedMin*iGetFanSpeedMin)
{
	this->iGetFanInfos=iGetFanInfos;
	this->nIGetFanInfos=nIGetFanInfos;
	this->iGetFanSpeedMin = iGetFanSpeedMin;

}
void Fans::GetFansWorkingCorrectly(bool& successful, Exceptions& exceptions){
if(nIGetFanInfos<=0){
	exceptions.Add(new Exception("There are no fans"));
successful= false;
return;}
	uint16_t minSpeed = iGetFanSpeedMin->GetFanSpeedMin();
	for(char i=0; i<nIGetFanInfos; i++    ){
		IGetFanInfo* iGetFanInfo = iGetFanInfos[i];
		iGetFanInfo->Check(successful, exceptions);
		return;
		if(successful){
			uint16_t speed = iGetFanInfo->GetFanSpeed(successful, exceptions);
			if(successful){
				if(minSpeed>speed){
						exceptions.Add(new FanSpeedException(iGetFanInfo->GetName(), speed, minSpeed));
				
				return;}
			}
			else
			{
					exceptions.Add(new CommunicationException("TC654"));
			
			return;}
	}
	else break;
	}
}