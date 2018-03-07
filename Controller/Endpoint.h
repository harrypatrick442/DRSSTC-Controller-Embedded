/*
* Endpoint.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __ENDPOINT_H__
#define __ENDPOINT_H__

#include "Exception.h"
#include "Exceptions.h"
#include "IGetMessages.h"
#include "ISendMessage.h"
#include "IGetRGBC.h"
#include "ISetFastMode.h"
#include "ISystemCheck.h"
#include "ITests.h"
#include "Sender.h"

class Endpoint
{
	//variables
	public:
	protected:
	private:
	IGetMessages* iGetMessages;
	ISendMessage* iSendMessage;
	ISystemCheck* iSystemCheck;
	ISetFastMode* iSetFastMode;
	ITests* iTests;
	IGetRGBC*iGetRGBC;
	Sender* sender;
	//functions
	public:
	Endpoint(IGetMessages* iGetMessages, ISendMessage* iSendMessage , Sender* sender, ISetFastMode*iSetFastMode, IGetRGBC*iGetRGBC, ISystemCheck* iSystemCheck, ITests* iTests);
	~Endpoint();
	void Run();
	protected:
	private:
	void GetRGBC();
	void EnableFastMode();
	void DissableFastMode();
	void SendException(Exception* exception);
	void SendExceptions(Exceptions* exceptions);
	void Test();
	void GetUnitTestsNames();
}; //Outputs

#endif //__ENDPOINT_H__
