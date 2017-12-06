/*
* Outputs.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include <avr/io.h>
#include "ErrorMessage.h"

// default constructor
ErrorMessage::ErrorMessage(char* message):message(message)
{
} //Outputs

// default destructor
ErrorMessage::~ErrorMessage()
{
} //~Fans