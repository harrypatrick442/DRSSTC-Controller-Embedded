/*
* Endpoint.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __ENDPOINT_H__
#define __ENDPOINT_H__


#include "Messages.h"
#include "IGetMessages.h"
#include "ISendMessage.h"
#include "ISetTemperatureMax.h"
#include "IGetTemperatureMax.h"
#include "ISetPower.h"
#include "IGetPower.h"
#include "ISystemCheck.h"
#include "ITemperatures.h"
#include "Exception.h"
#include "Exceptions.h"
class Endpoint
{
	//variables
	public:
	protected:
	private:
	IGetMessages* iGetMessages;
	ISendMessage* iSendMessage;
	ISetTemperatureMax* iSetTemperatureMax;
	IGetTemperatureMax* iGetTemperatureMax;
	ISetPower* iSetPower;
	IGetPower* iGetPower;
	ITemperatures* iTemperatures;
	ISystemCheck* iSystemCheck;
	//functions
	public:
	Endpoint(IGetMessages* iGetMessages, ISendMessage* iSendMessage, ISetTemperatureMax*iSetTemperatureMax, IGetTemperatureMax* iGetTemperatureMax, ISetPower* iSetPower, IGetPower* iGetPower, ITemperatures* iTemperatures,  ISystemCheck* iSystemCheck);
	~Endpoint();
	void Run();
	protected:
	private:
	void GetTemperatureMax();
	void GetMaxTemperature();//actual 
	void GetPower();
	void SendException(Exception& exception);
	void SendExceptions(Exceptions& exceptions);
}; //Outputs

#endif //__ENDPOINT_H__
