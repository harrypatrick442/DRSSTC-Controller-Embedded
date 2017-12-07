/*
* TC654Exception.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __TC654EXCEPTION_H__
#define __TC654EXCEPTION_H__
#include "Exception.h"
class TC654Exception:public Exception
{
	//variables
	public:
	typedef enum Type{Fault, CounterOverflow};
	protected:
	private:
	const Type type;
	const char* name;
	char* message=NULL;
	//functions
	public:
	TC654Exception(const char* name,  Type  type);
	~TC654Exception();
	const char* ToString();
	protected:
	private:
}; //Outputs

#endif __TC654EXCEPTION_H__



