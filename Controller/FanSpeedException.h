/*
* FanSpeedException.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/
#ifndef __FANSPEEDEXCEPTION_H__
#define __FANSPEEDEXCEPTION_H__
#include "Exception.h"

class FanSpeedException:public Exception
{
	//variables
	public:
	protected:
	private:
	const char* name;
	uint16_t actualSpeed;
	uint16_t minSpeedRequired;
	char* message;
	//functions
	public:
	FanSpeedException( const char* name, uint16_t actualSpeed, uint16_t minSpeedRequired);
	~FanSpeedException();
	virtual const char* ToString();
	protected:
	private:
}; //Outputs

#endif __FANSPEEDEXCEPTION_H__



