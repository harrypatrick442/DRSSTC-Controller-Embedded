/*
* Messages.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/
#include "Messages.h"
Messages::Messages(Message* messagesIn[], char lengthIn): length(lengthIn){
	messages = new Message*[lengthIn];
	for(char i=0; i<lengthIn; i++)
	messages[i]= messagesIn[i];
}
Messages::~Messages(){

	for(char i=0; i<length; i++)
	{
		delete messages[i];
	}
	delete[] messages;
}