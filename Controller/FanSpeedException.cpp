/*
* FanSpeedException.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "FanSpeedException.h"

FanSpeedException::FanSpeedException(const char* name, uint16_t actualSpeed, uint16_t minSpeedRequired):name(name), actualSpeed(actualSpeed), minSpeedRequired(minSpeedRequired)
{
}

FanSpeedException::~FanSpeedException()
{
	if(message!=NULL) delete message;
}
const char* FanSpeedException::ToString(){
	if(message==NULL){
		size_t totalLength = strlen(name)+70;
		message=(char*)malloc(sizeof(char)*totalLength);
		if(message!=NULL){
			snprintf(message,totalLength, "%s is going slower than the minimum speed setting, at %04d instead of %04d RPM.", name, actualSpeed, minSpeedRequired);
		}
	}
	return message;
}