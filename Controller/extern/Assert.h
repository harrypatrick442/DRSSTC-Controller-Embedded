/*
* ColourSensorTCS34725.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __ASSERT_H__
#define __ASSERT_H__
#include "ISendMessage.h"
#include "Exceptions.h"
class Assert
{
	public:
	static bool IsTrue(bool passed, const char* nameP, const char* exception, ISendMessage* iSendMessage);
	static bool DoesntThrowException(Exceptions& exceptions, const char* nameP , ISendMessage* iSendMessage);
	static void SendResponse(bool passed, const char* exception, const char* name, ISendMessage* iSendMessage);
	protected:
	private:
};

#endif
