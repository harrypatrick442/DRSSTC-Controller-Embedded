/*
* Exception.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include <stdlib.h>
#include "Exception.h"

// default constructor
Exception::Exception()
{
} //Outputs
Exception::Exception(char* message):message(message)
{
} //Outputs

// default destructor
Exception::~Exception()
{
if(message!=NULL){
delete message;
}
} //~Fans

const char* Exception::ToString(){

}
