/*
* Settings.cpp
*
* Created: 20/11/2017 21:01:43
* Author: SoftwareEngineer
*/


#include "Sender.h"
#include <string.h>



Sender::Sender(ISendMessage* iSendMessage):iSendMessage(iSendMessage){
	
}
void Sender::SendRGBC(RGBC rgbc){
	Cleanup<char*> s = rgbc.ToString();
	iSendMessage->SendMessage(s.payload, strlen(s.payload));
}