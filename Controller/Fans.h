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
#include "IGetErrors.h"
#include "IGetFanSpeedMin.h"
class Fans:
public   IFans
{
	//variables
	public:
	protected:
	private:
	ErrorMessages* errorMessages;
	static Fans _Singleton;
	IGetFanInfo** iGetFanInfos;
	unsigned char nIGetFanInfos;
	IGetFanSpeedMin * iGetFanSpeedMin;
	//functions
	public:
	static  Fans& GetInstance();
	void SetInterfaces(IGetFanInfo** iGetFanInfos, unsigned char nIGetFanInfos, IGetFanSpeedMin* iGetFanSpeedMin);
	bool GetFansWorkingCorrectly();
	ErrorMessages* GetErrors();
	protected:
	private:
	void operator=(Fans const&) = delete; // Don't implement

};

#endif
