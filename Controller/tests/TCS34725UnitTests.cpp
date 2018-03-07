/*
* TC654.cpp
*
* Created: 08/10/2017 12:37:23
* Author: SoftwareEngineer
*/
#include "../TCS34725Helper.h"
#include "CommunicationException.h"
#include "TCS34725UnitTests.h"
#include "Assert.h"
#include "../Leds.h"
#include <stdio.h>
void TCS34725UnitTests::TestGetATime::Run(bool&successful, Exceptions& exceptions, ISendMessage*iSendMessage){
	Assert::IsTrue(TCS34725Helper::GetATime(24)==0x0a,PSTR("GetATime"), PHelper::Marshal(PSTR("GetATime test failed!")).payload, iSendMessage);
}
void TCS34725UnitTests::TestGetAGain::Run(bool& successful, Exceptions& exceptions, ISendMessage*iSendMessage){
	Assert::IsTrue(TCS34725Helper::GetAGain(1)==0x00,PSTR("GetAGain"), PHelper::Marshal(PSTR("GetAGain test failed!")).payload, iSendMessage);
}
//((wait_ms × 0.065) + (atime_ms × 0.235) + (2.40 × 0.235)) / (atime_ms+wait_ms+2.4)  =current uA
//(240 × 0.065) + (43.2 × 0.235) + (2.40 × 0.235)) / (285.6)=92.1
//(720 × 0.065) + (43.2 × 0.235) + (2.40 × 0.235)) / (765.6)=75.1
void  TCS34725UnitTests::TestCalculateWait::Run(bool& successful, Exceptions& exceptions, ISendMessage*iSendMessage){
	TCS34725Helper::Wait wait = TCS34725Helper::CalculatWait(92, 18);
	if(wait.time!=100){
	char exception[60];
	snprintf_P(exception,60, PSTR("GetCalculateWait test failed with WTIME: %04d and WLONG: %01d."), wait.time, wait.isLong);
		Assert::IsTrue(false ,PSTR("CalculateWait"), exception, iSendMessage);
		return;
	}
	wait = TCS34725Helper::CalculatWait(75, 18);
	char exception2[61];
	snprintf_P(exception2,61, PSTR("GetCalculateWait test2 failed with WTIME:  %04d and WLONG: %01d."), wait.time, wait.isLong);
	Assert::IsTrue(wait.time==25,PSTR("CalculateWait"), exception2, iSendMessage);
}
void  TCS34725UnitTests::TestGetRGBA::Run(bool& successful, Exceptions& exceptions, ISendMessage*iSendMessage){
	Exceptions ex;
	Leds::GetInstance().GetBacklight()->TurnOn();
	RGBC rgbc=iGetRGBC->GetRGBC(successful, ex);
	Cleanup<char*> s = rgbc.ToString();
	iSendMessage->SendMessage(s.payload, strlen(s.payload));
	Assert::DoesntThrowException(ex,PSTR("GetRGBA"), iSendMessage);
}
void TCS34725UnitTests::TestBacklight::Run(bool&successful, Exceptions& exceptions, ISendMessage* iSendMessage){
	
}

