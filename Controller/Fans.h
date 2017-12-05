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

class Fans:
public IFans
{
	//variables
	public:
	protected:
	private:
	static Fans _Singleton;
	IGetFanInfo** iGetFanInfos;
	unsigned char nIGetFanInfos;
	//functions
	public:
	static  Fans& GetInstance();
	void SetInterfaces(IGetFanInfo** iGetFanInfos, unsigned char nIGetFanInfos);
	bool GetFansWorkingCorrectly();
	ErrorMessage GetErrors();
	protected:
	private:
	void Initialize ();
	void operator=(Fans const&) = delete; // Don't implement

};

#endif
