/*
* CommunicationException.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __COMMUNICATIONEXCEPTION_H__
#define __COMMUNICATIONEXCEPTION_H__
#include "Exception.h"
class CommunicationException:public Exception
{
	//variables
	public:
	protected:
	private:
	const char* deviceName;
	char* message;
	//functions
	public:
	CommunicationException(const char* deviceName);
	~CommunicationException();
	virtual const char* ToString();
	protected:
	private:
}; //Outputs

#endif __COMMUNICATIONEXCEPTION_H__



