/*
* ColourSensorTCS34725.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __TESTS_H__
#define __TESTS_H__

#include "Exception.h"
#include "Exceptions.h"
#include "ITests.h"
#include "TCS34725UnitTests.h"
#include "ISendMessage.h"
#include "ITest.h"
#include "Test.h"
#include "../IGetRGBC.h"
class Tests:public ITests
{
	Test** tests
	;
	
	private:
	
	ISendMessage* iSendMessage;
	public:
	Tests(ISendMessage* iSendMessage, IGetRGBC* iGetRGBC);
	void DoTests(bool& successful, Exceptions& exceptions);
	void GetTestNames();
	protected:
	private:
	void SendP(const char* str);
	void Send(const char* str);
	//functions
	public:
	protected:
	private:
};

#endif
