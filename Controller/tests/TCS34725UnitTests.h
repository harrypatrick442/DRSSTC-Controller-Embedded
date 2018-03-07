/*
* TCS34725.h
*
* Created: 08/10/2017 12:37:23
* Author: SoftwareEngineer
*/


#ifndef __TCS34725UnitTests_H__
#define __TCS34725UnitTests_H__
#include "Exceptions.h"
#include "Test.h"
#include "ISendMessage.h"
#include "Cleanup.h";
#include "../IGetRGBC.h"
#include <avr/pgmspace.h>
class TCS34725UnitTests
{
	public:
	class TestGetATime: public Test
	{
		public:
		TestGetATime():Test(){}
		void Run(bool& successful, Exceptions& exceptions, ISendMessage*iSendMessage);
		Cleanup<const char*> GetName (){
		return Test::_GetName(PSTR("GetATime"));
		}
	};
	class TestGetAGain:public Test{
		public:
		TestGetAGain():Test(){}
		void Run(bool& successful, Exceptions& exceptions, ISendMessage*iSendMessage);
		Cleanup<const char*> GetName (){
			return Test::_GetName(PSTR("GetAGain"));
		}
};
class  TestCalculateWait:public Test{
	public:
	TestCalculateWait():Test(){}
	void Run(bool& successful, Exceptions& exceptions, ISendMessage*iSendMessage);
	Cleanup<const char*> GetName (){
		return Test::_GetName(PSTR("CalculateWait"));
	}
};
class  TestGetRGBA:public Test{
	private:
	IGetRGBC* iGetRGBC;
	public:
	TestGetRGBA(IGetRGBC* iGetRGBC): Test() , iGetRGBC(iGetRGBC) {}
	void Run(bool& successful, Exceptions& exceptions, ISendMessage*iSendMessage);
	Cleanup<const char*> GetName (){
		return Test::_GetName(PSTR("GetRGBA"));
	}
};
class  TestBacklight:public Test{
	public:
	TestBacklight():Test(){}
	void Run(bool& successful, Exceptions& exceptions, ISendMessage*iSendMessage);
	Cleanup<const char*> GetName (){
		return Test::_GetName(PSTR("Backlight"));
	}
};
};

#endif