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

Fans& Fans::GetInstance(){
	
} void Fans::SetInterfaces(IGetFanInfo** iGetFanInfos, unsigned char nIGetFanInfos, IGetFanSpeedMin*iGetFanSpeedMin)
{
	this->iGetFanInfos=iGetFanInfos;
	this->nIGetFanInfos=nIGetFanInfos;
	this->iGetFanSpeedMin = iGetFanSpeedMin;

}
bool Fans::GetFansWorkingCorrectly(Exceptions& exceptions){
	uint16_t minSpeed = iGetFanSpeedMin->GetFanSpeedMin();
	for(char i=0; i<nIGetFanInfos; i++    ){
		IGetFanInfo* iGetFanInfo = iGetFanInfos[i];
		bool successful=true;
		iGetFanInfo->Check(successful, exceptions);
		if(successful){
			uint16_t speed = iGetFanInfo->GetFanSpeed(successful, exceptions);
			if(successful){
				if(minSpeed>speed){
						exceptions->Add(new FanSpeedException(iGetFanInfo->GetName(), speed, minSpeed));
				}
				else
				return true;
			}
			else
			{
					exceptions->Add(new CommunicationException("TC654"));
			}
		}
	}
	if(nIGetFanInfos<=0)
		exceptions->Add(new Exception("There are no fans"));
	return false;
}