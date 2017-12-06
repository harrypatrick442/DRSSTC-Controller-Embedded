/*
* Outputs.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __ERRORMESSAGES_H__
#define __ERRORMESSAGES_H__


#include "ErrorMessage.h"
class ErrorMessages
{
	//variables
	public:
	const unsigned int nMessages;
	const ErrorMessage* messages;
	protected:
	private:
	//functions
	public:
	ErrorMessages(ErrorMessage* errorMessages, unsigned int nMessages);
	~ErrorMessages();
	protected:
	private:
}; //ErrorMessages

#endif __ERRORMESSAGES_H__
