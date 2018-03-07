/*
* CommunicationException.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "CommunicationException.h"

CommunicationException::CommunicationException(const char* deviceName):deviceName(deviceName)
{
}

CommunicationException::~CommunicationException()
{
	this->~Exception();
}
const char* CommunicationException::ToString(){

	if(message==NULL){
		size_t totalLength = strlen(deviceName)+27;
		message=(char*)malloc(totalLength);
			snprintf(message,totalLength, "Communication with %s failed", deviceName);
	}
	return message;
}