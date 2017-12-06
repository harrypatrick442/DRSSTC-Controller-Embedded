/*
* Outputs.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include <avr/io.h>
#include "Fans.h"

Fans& Fans::GetInstance(){
	
}void Fans::SetInterfaces(IGetFanInfo** iGetFanInfos, unsigned char nIGetFanInfos, IGetFanSpeedMin*iGetFanSpeedMin)
{
this->iGetFanInfos=iGetFanInfos;
this->nIGetFanInfos=nIGetFanInfos;
this->iGetFanSpeedMin = iGetFanSpeedMin;

}
bool Fans::GetFansWorkingCorrectly(){
	bool working=true;
	for(char i=0; i<nIGetFanInfos; i++    ){
		IGetFanInfo* iGetFanInfo = iGetFanInfos[i];
		bool successful=true;
		uint16_t speed = iGetFanInfo->GetFanSpeed(successful);
		if(speed)
		{
			
		}
	}
}
ErrorMessages* Fans::GetErrors(){
	
}