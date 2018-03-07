/*
* ColourSensorTCS34725.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __ITEST_H__
#define __ITEST_H__

#include "Exception.h"
#include "Exceptions.h"
class ITest
{
	public:
	virtual void Run(bool& successful, Exceptions& exceptions, ISendMessage*iSendMessage)=0;
	virtual const char* GetName ()=0;
};

#endif
