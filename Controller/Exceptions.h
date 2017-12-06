/*
* Outputs.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__


#include "Exception.h"
class Exceptions
{
	//variables
	public:
	const unsigned int nExceptions;
	Exception*const*const exceptions;
	protected:
	private:
	//functions
	public:
	Exceptions(Exception* *const  exceptions, unsigned int nExceptions);
	~Exceptions();
	protected:
	private:
}; //Exceptions

#endif __EXCEPTIONS_H__
