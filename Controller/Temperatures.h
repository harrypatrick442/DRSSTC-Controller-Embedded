/* 
* Temperatures.h
*
* Created: 08/10/2017 12:37:23
* Author: SoftwareEngineer
*/


#ifndef __Temperatures_H__
#define __Temperatures_H__
#include "IGetTemperatureInfo.h"
#include "ITemperatures.h"

class Temperatures:
public ITemperatures
{
	//variables
	public:
	protected:
	private:
	static Temperatures _Singleton;
	IGetTemperatureInfo** iGetTemperatureInfos;
	 unsigned char nIGetTemperatureInfos;
	//functions
	public:
	static  Temperatures& GetInstance();
	void SetInterfaces(IGetTemperatureInfo** iGetTemperatureInfos, unsigned char nIGetTemperatureInfos);
	int8_t GetMaxTemperature(bool& successful, Exceptions& exceptions);
	protected:
	private:
	void Initialize ();
	void operator=(Temperatures const&) = delete; // Don't implement

};

#endif
