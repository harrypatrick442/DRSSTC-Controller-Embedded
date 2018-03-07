/*
* Exception.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__
#include <cstddef>
class Exception
{
	//variables
	public:
	protected:
	char* message=NULL;
	//functions
	public:
	Exception();
	Exception(char* message);
	~Exception();
	virtual const char* ToString();
	protected:
	private:
}; //Outputs

#endif //__EXCEPTION_H__



