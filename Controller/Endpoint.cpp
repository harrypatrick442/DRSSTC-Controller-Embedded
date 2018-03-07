/*
* Endpoint.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include "Leds.h"
#include "tiny-json.h"
#include "Leds.h"
#include "Endpoint.h"
#include "Exceptions.h"
#include "RGBC.h"
#include "UART.h"
#include "ITests.h"

#include <avr/pgmspace.h>
#include<stdio.h>
#include <string.h>
Endpoint::Endpoint(IGetMessages* iGetMessages, ISendMessage* iSendMessage, Sender* sender, ISetFastMode*iSetFastMode, IGetRGBC*iGetRGBC, ISystemCheck* iSystemCheck , ITests* iTests):iGetMessages(iGetMessages), iSendMessage(iSendMessage), iSetFastMode(iSetFastMode), iGetRGBC (iGetRGBC), iSystemCheck(iSystemCheck), sender(sender) ,  iTests(iTests){
	
}
void Endpoint::Run(){
	Messages* messages = iGetMessages->GetMessages();
	if(messages!=NULL){
		if(messages->length>0)
		{
			for(int i=0; i<messages->length; i++){
				Message* message = messages->messages[i];
				json_t pool[64];
				json_t const* root = json_create( (char*)message->buffer, pool, message->length );
				json_t const* jObjectType = json_getProperty( root, "type" );
				if ( jObjectType && JSON_TEXT == json_getType(  jObjectType ) ) {
					const char* type = json_getValue(jObjectType);
					if(strcmp_P(type,PSTR("enable_fast_mode"))==0){
						EnableFastMode();
						}else{
						if(strcmp_P(type,PSTR("dissable_fast_mode"))==0){
							DissableFastMode();
						}else
						if(strcmp_P(type,PSTR("get_rgbc"))==0){
							GetRGBC();
						}
						else
						if(strcmp_P(type,PSTR("test"))==0){
							Test();
						}
						else
						if(strcmp_P(type,PSTR("get_unit_tests_names"))==0){
							GetUnitTestsNames();
						}
						else
						if(strcmp_P(type,PSTR("unit_tests"))==0){
							
							Exceptions exceptions;
							bool successful=true;
							iTests->DoTests(successful, exceptions);
							
						}
					}
				}
			}
		}
		delete messages;
	}
}

void Endpoint::Test()
{
	char buffer[17];
	strcpy_P(buffer, PSTR("{\"type\":\"test\"}\n"));
	iSendMessage->SendMessage(buffer ,16 );
}
void Endpoint::GetUnitTestsNames(){
	iTests->GetTestNames();
}
void Endpoint::GetRGBC(){
	bool successful=true;
	Exceptions exceptions;
	RGBC rgbc=iGetRGBC->GetRGBC(successful, exceptions);
	if(successful){
		sender->SendRGBC(rgbc);
	}
	else
	SendExceptions(&exceptions);
}

void Endpoint::EnableFastMode(){
	bool successful=true;
	Exceptions exceptions;
	
	iSetFastMode->SetFastMode(true, successful, exceptions);
	if(successful){
		
		char buffer[25];
		strcpy_P(buffer, PSTR("{\"type\":\"in_fast_mode\"}\n"));
		iSendMessage->SendMessage(buffer, 24);
	}
	else
	SendExceptions(&exceptions);
}
void Endpoint::DissableFastMode(){
	bool successful=true;
	Exceptions exceptions;
	
	iSetFastMode->SetFastMode(false, successful, exceptions);
	if(successful){
		
		char buffer[29];
		strcpy_P(buffer, PSTR("{\"type\":\"not_in_fast_mode\"}\n"));
		iSendMessage->SendMessage(buffer, 28);
	}
	else
	SendExceptions(&exceptions);
}
void Endpoint::SendException(Exception* exception){
	const char* message = exception->ToString();
	unsigned int length = strlen(message) + 35;
	char* buf  = (char*) malloc(length);
	snprintf_P(buf,length,PSTR("{\"type\":\"exception\",\"message\":\"%s\"}\n"),message);
	iSendMessage->SendMessage(buf, length-1);
	free(buf);
}
void Endpoint::SendExceptions(Exceptions* exceptions){
	for(unsigned int i=0; i<exceptions->Count(); i++){
		Exception* exception = exceptions->exceptions[i];
		SendException(exception);
	}
}
