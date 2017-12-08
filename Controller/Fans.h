/*
* Fans.h
*
* Created: 08/10/2017 12:37:23
* Author: SoftwareEngineer
*/


#ifndef __Fans_H__
#define __Fans_H__
#include "IGetFanInfo.h"
#include "IFans.h"
#include "IGetExceptions.h"
#include "IGetFanSpeedMin.h"
#include "Exceptions.h"
class Fans:
public   IFans
{
	//variables
	public:
	protected:
	private:
	Exceptions* exceptions;
	static Fans _Singleton;
	IGetFanInfo** iGetFanInfos;
	unsigned char nIGetFanInfos;
	IGetFanSpeedMin * iGetFanSpeedMin;
	//functions
	public:
	static  Fans& GetInstance();
	void SetInterfaces(IGetFanInfo** iGetFanInfos, unsigned char nIGetFanInfos, IGetFanSpeedMin* iGetFanSpeedMin);
	void GetFansWorkingCorrectly(bool& successful, Exceptions& exceptions);
	protected:
	private:
	void operator=(Fans const&) = delete; // Don't implement

};

#endif
