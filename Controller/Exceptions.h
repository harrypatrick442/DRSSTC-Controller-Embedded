/*
* Outputs.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__


#include "simple_vector.h"
#include "Exception.h"
class Exceptions
{
	//variables
	public:
	simple_vector<Exception*>exceptions;
	protected:
	private:
	//functions
	public:
	void Consume(Exceptions* exceptions);
	void Add(Exception* exception);
	unsigned int Count();
	Exceptions();
	~Exceptions();
	protected:
	private:
}; //Exceptions

#endif __EXCEPTIONS_H__
