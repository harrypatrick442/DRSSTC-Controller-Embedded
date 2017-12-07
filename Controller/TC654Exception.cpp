/*
* TC654Exception.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include <avr/io.h>
#include "TC654Exception.h"

// default constructor
TC654Exception::TC654Exception(const char* name, Type type):name(name), type(type)
{
	
} //TC654Exception

// default destructor
TC654Exception::~TC654Exception()
{
	if(message!=NULL){
	delete message;
	}
} //~TC654Exception
char* TC654Exception::ToString(){
	if(message==NULL){
	switch(type){
		case Fault:
		size_t totalLength = strlen(name)+57;
		message=(char*)malloc(sizeof(char)*totalLength);
		snprintf(message, "%s experienced a fault as indicated by its status register", name);
		break;
		case CounterOverflow:
		size_t totalLength = strlen(name)+68;
		message=char(*)malloc(sizeof(char)*totalLength);
		snprintf(message, "%s experienced a counter overflow as indicated by its status register",name);
		break;
	}
	return message;
	}
}