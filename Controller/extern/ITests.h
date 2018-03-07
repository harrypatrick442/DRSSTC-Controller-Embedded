/*
* ColourSensorTCS34725.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __ITESTS_H__
#define __ITESTS_H__

#include "Exception.h"
#include "Exceptions.h"
class ITests
{
	public:
	virtual void DoTests(bool& successful, Exceptions& exceptions)=0;
	virtual void GetTestNames();
}; 

#endif
