/*
* Endpoint.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include "ColourSensorTCS34725.h"
#include "Exceptions.h"
#include "RGBC.h"
#include "UART.h"
#include <string.h>
ColourSensorTCS34725::ColourSensorTCS34725(TCS34725* tcs34725, ISendRGBC* iSendRGBC, ISubscriptionRunner* iSubscriptionRunner, ILed* iLedSource): tcs34725(tcs34725), iSendRGBC(iSendRGBC), iSubscriptionRunner(iSubscriptionRunner), iLedSource(iLedSource), state(Running){
	
}
void ColourSensorTCS34725::SetFastMode (bool fast, bool& successful, Exceptions& exceptions){
	this->fast=fast;
	if(fast)
	{
		iSubscriptionRunner->Subscribe(this);
	}
	else
	{
		iSubscriptionRunner->Unsubscribe(this);
	}
}

void ColourSensorTCS34725::Run(){

}
void ColourSensorTCS34725::_Run(){
	bool successful = true;
	Exceptions exceptions;
	RGBC rgbc = tcs34725->GetRGBC(successful, exceptions);
	if(successful)
	{
		iSendRGBC->SendRGBC(rgbc);
	}
}
RGBC ColourSensorTCS34725::GetRGBC(bool& successful , Exceptions& exceptions){
	return tcs34725->GetRGBC(successful, exceptions);
}