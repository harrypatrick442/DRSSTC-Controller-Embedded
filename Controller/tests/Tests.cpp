/*
* Endpoint.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include "Tests.h"
#include <string.h>
#include "TCS34725UnitTests.h"
#include "PHelper.h"
#include "../IGetRGBC.h"
#include <avr/pgmspace.h>

#define TESTS_SIZES 4
Tests::Tests(ISendMessage* iSendMessage, IGetRGBC* iGetRGBC):iSendMessage(iSendMessage){
	
	tests =new Test*[TESTS_SIZES];
	Test* stck[TESTS_SIZES]={
		new TCS34725UnitTests::TestGetATime(),
		new TCS34725UnitTests::TestCalculateWait(),
		new TCS34725UnitTests::TestGetAGain(),
		new TCS34725UnitTests::TestGetRGBA(iGetRGBC)
		};
	for(size_t i=0; i<TESTS_SIZES; i++) {
		tests[i]=stck[i];
	}
}
void Tests::DoTests(bool& successful, Exceptions& exceptions){
	for(size_t i=0; i<TESTS_SIZES; i++)
	{
		Test* test = tests[i];
		test->Run(successful, exceptions, iSendMessage);
	}
}

void Tests::GetTestNames(){
	bool first= true;
	SendP(PSTR("{\"type\":\"unit_tests_names\",\"names\":["));
		for(size_t i=0; i<TESTS_SIZES; i++)
		{
			if(first){
				first=false;
				SendP(PSTR("\""));
			}
			else{
				SendP(PSTR(",\""));
			}
			Test* test = tests[i];
			Send(test->GetName().payload);
			SendP(PSTR("\""));
		}
	SendP(PSTR("]}\n"));
}
void Tests::SendP(const char* str){
	PHelper::SendP(str, iSendMessage);
}
void Tests::Send(const char* str){
	iSendMessage->SendMessage(str, strlen(str));
}