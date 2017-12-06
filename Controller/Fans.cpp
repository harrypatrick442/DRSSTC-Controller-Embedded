/*
* Outputs.cpp
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

Fans& Fans::GetInstance(){
	
}void Fans::SetInterfaces(IGetFanInfo** iGetFanInfos, unsigned char nIGetFanInfos, IGetFanSpeedMin*iGetFanSpeedMin)
{
this->iGetFanInfos=iGetFanInfos;
this->nIGetFanInfos=nIGetFanInfos;
this->iGetFanSpeedMin = iGetFanSpeedMin;

}
PassFailCleanup Fans::GetFansWorkingCorrectly(){
	bool working=true;
	uint16_t minSpeed = iGetFanSpeedMin->GetFanSpeedMin();
	Exception** const exceptions = (Exception **const)malloc(sizeof(Exception*)*MAX_NUMBER_EXCEPTIONS);
	unsigned int nException=0;
	for(char i=0; i<nIGetFanInfos; i++    ){
		IGetFanInfo* iGetFanInfo = iGetFanInfos[i];
		bool successful=true;
		uint16_t speed = iGetFanInfo->GetFanSpeed(successful);
		if(successful){
		if(minSpeed>speed){
		if(nException<MAX_NUMBER_EXCEPTIONS){
			exceptions[nException]= new FanSpeedException(iGetFanInfo->GetName(), speed, minSpeed);
			nException++;}
		}
		}else
		{
		if(nException<MAX_NUMBER_EXCEPTIONS){
			exceptions[nException]= new CommunicationException(iGetFanInfo->GetName());
			nException++;}
		}
	}
	return (nException>0?PassFailCleanup(new Exceptions(exceptions, nException)):PassFailCleanup());
}
Exceptions* Fans::GetExceptions(){
	
}