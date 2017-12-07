/*
* Outputs.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "CommunicationException.h"

// default constructor
CommunicationException::CommunicationException(const char* deviceName):deviceName(deviceName)
{
} //Outputs

// default destructor
CommunicationException::~CommunicationException()
{
} //~Fans
const char* CommunicationException::ToString(){

	if(message==NULL){
		size_t totalLength = strlen(deviceName)+27;
		message=(char*)malloc(sizeof(char)*totalLength);
		if(message!=NULL){
			snprintf(message,totalLength, "Communication with %s failed", deviceName);
		}
	}
	return message;
}