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
#include "Exceptions.h"
#include "PassFailCleanup.h"

Fans& Fans::GetInstance(){
	
} void Fans::SetInterfaces(IGetFanInfo** iGetFanInfos, unsigned char nIGetFanInfos, IGetFanSpeedMin*iGetFanSpeedMin)
{
	this->iGetFanInfos=iGetFanInfos;
	this->nIGetFanInfos=nIGetFanInfos;
	this->iGetFanSpeedMin = iGetFanSpeedMin;

}
PassFailCleanup<Exceptions*> Fans::GetFansWorkingCorrectly(){
	bool working=true;
	uint16_t minSpeed = iGetFanSpeedMin->GetFanSpeedMin();
	Exceptions* exceptions = new Exceptions();
	for(char i=0; i<nIGetFanInfos; i++    ){
		IGetFanInfo* iGetFanInfo = iGetFanInfos[i];
		bool successful=true;
		PassFailCleanup<Exceptions*> passFailCleanup=iGetFanInfo->Check();
		if(passFailCleanup.successful){
			uint16_t speed = iGetFanInfo->GetFanSpeed(successful);
			if(successful){
				if(minSpeed>speed){
						exceptions->Add(new FanSpeedException(iGetFanInfo->GetName(), speed, minSpeed));
				}
			}
			else
			{
					exceptions->Add(new CommunicationException(iGetFanInfo->GetName()));
			}
		}
		else
		{
			exceptions->Consume(passFailCleanup.payload);
		}
	}
if(exceptions->Count()>0){
return PassFailCleanup<Exceptions*>(exceptions);
}
delete exceptions; 
return PassFailCleanup<Exceptions*>();
}