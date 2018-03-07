/*
* Assert.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include "Assert.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<avr/pgmspace.h>
#include "PHelper.h"
bool Assert::IsTrue(bool passed, const char* nameP,  const char* exception, ISendMessage* iSendMessage)
{
	SendResponse(passed, exception, nameP, iSendMessage);
	return !passed;
}

void Assert::SendResponse(bool passed, const char* exception, const char* nameP, ISendMessage*iSendMessage){
	PHelper::SendP(PSTR("{\"type\":\"unit_test\",\"name\":\""), iSendMessage);
		PHelper::SendP(nameP, iSendMessage);
		if(passed)
		{
		PHelper::SendP(PSTR("\",\"passed\":true}\n"), iSendMessage);
	}
	else
	{
		PHelper::SendP(PSTR("\",\"exception\":\""), iSendMessage);
		iSendMessage->SendMessage(exception, strlen(exception));
	PHelper::SendP(PSTR("\",\"passed\":false}\n"), iSendMessage);
}
}
bool Assert::DoesntThrowException(Exceptions& exceptions, const char* nameP , ISendMessage* iSendMessage){
	bool passed = exceptions.Count()<=0;
	SendResponse(passed, passed?NULL:exceptions.exceptions[0]->ToString(), nameP, iSendMessage);
	return exceptions.Count()>0;
}
