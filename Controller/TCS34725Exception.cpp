/*
* TC654Exception.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<avr/pgmspace.h>
#include "TCS34725Exception.h"

// default constructor
TCS34725Exception::TCS34725Exception(const char* name, char* subMessage, Type type):name(name), type(type)
{
if(subMessage!=NULL)
		subMessage=(char*)malloc(strlen(subMessage)+1);
} //TC654Exception

// default destructor
TCS34725Exception::~TCS34725Exception()
{
	if(subMessage!=NULL)
		delete subMessage;
	this->~Exception();
} //~TC654Exception
const char* TCS34725Exception::ToString(){
	if(message==NULL){
		size_t totalLength;
		switch(type){
			case Configuration:
			totalLength = strlen(name)+68;
			message=(char*)malloc(sizeof(char)*totalLength);
			if(message!=NULL){
				snprintf_P(message,totalLength, PSTR("%s experienced a configuration error: %s"),name, subMessage);
			}
			break;
			case Communication:
			totalLength = strlen(name)+68;
			message=(char*)malloc(sizeof(char)*totalLength);
			if(message!=NULL){
				snprintf_P(message,totalLength, PSTR("%s experienced a communication error: %s"),name, subMessage);
			}
			break;
		}
	}
	return message;
}