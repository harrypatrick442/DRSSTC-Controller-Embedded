/*
* ColourSensorTCS34725.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __NOTESTS_H__
#define __NOTESTS_H__
#include "ISendMessage.h"
#include "Exceptions.h"
#include "ITests.h"

class NoTests:public ITests
{
	public:
	NoTests();
	void DoTests(bool& successful, Exceptions& exceptions);
	void GetTestNames();
	protected:
	private:
	public:
	protected:
	private:
};

#endif
