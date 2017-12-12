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
#include "UART.h"
#include "LM75.h"
#include <string.h>
Endpoint::Endpoint(IGetMessages* iGetMessages, ISendMessage* iSendMessage, ISetTemperatureMax*iSetTemperatureMax, IGetTemperatureMax* iGetTemperatureMax, ISetPower* iSetPower, IGetPower* iGetPower, ITemperatures* iTemperatures, ISystemCheck* iSystemCheck):iGetMessages(iGetMessages), iSendMessage(iSendMessage), iSetTemperatureMax(iSetTemperatureMax), iGetTemperatureMax(iGetTemperatureMax), iSetPower(iSetPower), iGetPower(iGetPower), iTemperatures(iTemperatures), iSystemCheck(iSystemCheck){
	
}
void Endpoint::Run(){
	Messages* messages = iGetMessages->GetMessages();
	if(messages!=NULL){
		if(messages->length>0)
		{
			Leds::Main::SetGreen();
			for(int i=0; i<messages->length; i++){
				Message* message = messages->messages[i];
				json_t pool[64];
				json_t const* root = json_create( (char*)message->buffer, pool, message->length );
				json_t const* jObjectType = json_getProperty( root, "type" );
				if ( jObjectType && JSON_TEXT == json_getType(  jObjectType ) ) {
					
					
					const char* type = json_getValue(jObjectType);
					UART::GetInstance().SendMessage(type, strlen(type));
					if(strcmp(type, "system_check")==0){
					Exceptions exceptions;
						  bool successful=true;
						   iSystemCheck->Check(successful, exceptions);
						   if(successful){
						   iSendMessage->SendMessage("{\"type\":\"system_check\",\"passed\":true}\n", 38);
						   }
						   else{
						   SendExceptions(&exceptions);
						   iSendMessage->SendMessage("{\"type\":\"system_check\",\"passed\":false}\n", 39);
						   }
						}else{
						if(strcmp(type,"run")==0){
							
							}else{
							if(strcmp(type,"set_temperature_max")==0){
								json_t const* jObjectTemperatureMax = json_getProperty( root, "temperature_max" );
								if ( jObjectTemperatureMax!=NULL && JSON_INTEGER == json_getType(  jObjectTemperatureMax ) ) {
									int temperatureMax = json_getInteger(jObjectTemperatureMax);
									iSetTemperatureMax->SetTemperatureMax(temperatureMax);
								}
								}else{
								if(strcmp(type,"get_temperature_max")==0){
									GetTemperatureMax();
									}else{
									if(strcmp(type,"set_power"  )==0){
										json_t const* jObjectPower = json_getProperty( root, "power" );
										if ( jObjectPower && JSON_INTEGER == json_getType(  jObjectPower ) ) {
											int Power = json_getInteger(jObjectPower);
											iSetPower->SetPower(Power);
										}
										}else{
										if(strcmp(type,"get_power")==0){
											GetPower();
											}else{
											if(strcmp(type,"set_info_rate")==0){

												}else{
												if(strcmp(type, "get_max_temperature")==0 ){
													GetMaxTemperature();
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		delete messages;
	}
}

void Endpoint::GetPower(){
	uint16_t power = iGetPower->GetPower();
	char buf[31];
	snprintf(buf,31,"{\"type\":\"power\",\"power\":%04d}\n",power);
	iSendMessage->SendMessage(buf, 30);
}
void Endpoint::GetTemperatureMax(){
	uint8_t temperatureMax = iGetTemperatureMax->GetTemperatureMax();
	char buf[50];
	snprintf(buf,50,"{\"type\":\"temperature_max\",\"temperature_max\":%03d}\n",temperatureMax);
iSendMessage->SendMessage(buf, 49);}

void Endpoint::GetMaxTemperature(){
	bool successful=true;
	Exceptions exceptions;
	 
	int8_t temperature = iTemperatures->GetMaxTemperature(successful, exceptions);
	if(successful){
		Leds::Main::SetRed();
		char buf[46];
		snprintf(buf,46,"{\"type\":\"max_temperature\",\"temperature\":%03d}\n",temperature);
	iSendMessage->SendMessage(buf, 45);}
	else
	SendExceptions(&exceptions);
	}
	void Endpoint::SendException(Exception* exception){
	const char* message = exception->ToString();
		unsigned int length = strlen(message) + 35;
		char* buf  = (char*) malloc(length);
		snprintf(buf,length,"{\"type\":\"exception\",\"message\":\"%s\"}\n",message);
		iSendMessage->SendMessage(buf, length-1);
		free(buf);
	}
	    void Endpoint::SendExceptions(Exceptions* exceptions){
		for(unsigned int i=0; i<exceptions->Count(); i++){
			Exception* exception = exceptions->exceptions[i];
			SendException(exception);
		}
	}
