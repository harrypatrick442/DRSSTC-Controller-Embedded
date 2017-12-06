/*
* Exceptions.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include "Exceptions.h"

// default constructor
Exceptions::Exceptions(Exception**const exceptions, unsigned int nExceptions):nExceptions(nExceptions), exceptions(exceptions){} //Outputs

// default destructor
Exceptions::~Exceptions()
{
delete exceptions;
} //~Fans

