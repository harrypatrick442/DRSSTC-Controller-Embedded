/*
* PHelper.cpp
*
* Created: 08/10/2017 16:33:17
* Author: SoftwareEngineer
*/


#include "PHelper.h"
#include<avr/pgmspace.h>
Cleanup<const char*> PHelper::Marshal(const char* p){
	char* buffer=(char*)malloc(strlen_P(p)+1);
	strcpy_P(buffer, p);
	return Cleanup<const char*>((const char*)buffer);
}

void PHelper::SendP(const char* str, ISendMessage* iSendMessage){
	size_t length = strlen_P(str);
	char buffer[length+1];
	strcpy_P(buffer, str);
	iSendMessage->SendMessage(buffer, length);
}