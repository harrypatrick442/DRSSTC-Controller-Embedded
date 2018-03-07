/*
* TC654Exception.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __TCS34725EXCEPTION_H__
#define __TCS34725EXCEPTION_H__
#include "Exception.h"
class TCS34725Exception:public Exception
{
	//variables
	public:
	typedef enum Type{Configuration, Communication};
	protected:
	private:
	const Type type;
	const char* name;
	char* subMessage;
	//functions
	public:
	TCS34725Exception(const char* name, char* subMessage,  Type  type);
	~TCS34725Exception();
	virtual const char* ToString();
	protected:
	private:
}; 

#endif 



