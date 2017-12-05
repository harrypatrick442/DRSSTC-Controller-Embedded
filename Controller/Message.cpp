/*
* Messages.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/
#include "Message.h"
Message::Message(const char* bufferIn, unsigned int lengthIn):length(lengthIn), buffer(bufferIn){
	
}
Message::~Message(){
	delete[] this->buffer;
}