/*
* ColourSensorTCS34725.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __TEST_H__
#define __TEST_H__

#include <avr/pgmspace.h>
#include "Exception.h"
#include "Exceptions.h"
#include "ISendMessage.h"
#include "Cleanup.h"
#include "PHelper.h"
class Test
{
	public:
	Test(){}
	virtual void Run(bool& successful, Exceptions& exceptions, ISendMessage*iSendMessage)=0;
	virtual Cleanup<const char*> GetName ();
	protected:
	Cleanup<const char*> _GetName(const char* p){
		return PHelper::Marshal(p);
	}
}; //Outputs

#endif
