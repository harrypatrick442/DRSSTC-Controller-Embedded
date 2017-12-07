/*
* Temperatures.cpp
*
* Created: 08/10/2017 12:37:23
* Author: SoftwareEngineer
*/
//#include "i2cmaster.h"
#include "Temperatures.h"
#include "IGetTemperature.h"
#include "Exception.h"
#include "CommunicationException.h"
Temperatures Temperatures:: _Singleton;
Temperatures& Temperatures::GetInstance(){
	static bool initialized=false;
	if(!initialized)
	{
		_Singleton.Initialize();
		initialized=true;
	}
	return _Singleton;
}
void Temperatures::SetInterfaces(IGetTemperatureInfo** iGetTemperatureInfos, unsigned char  nIGetTemperatureInfos){
	this->iGetTemperatureInfos=iGetTemperatureInfos;
	this->nIGetTemperatureInfos=nIGetTemperatureInfos;
}
void Temperatures::Initialize(){

}
int8_t Temperatures::GetMaxTemperature(bool& successful, Exceptions& exceptions){
	if(nIGetTemperatureInfos>0)
	{
		//Leds::Main::SetRed();
		
		int8_t t=(*iGetTemperatureInfos)->GetTemperature(successful, exceptions);
		for(int i=1; successful&&(i<nIGetTemperatureInfos); i++)
		{
			IGetTemperatureInfo* iGetTemperatureInfo = *(iGetTemperatureInfos+i);
			int8_t n=iGetTemperatureInfo->GetTemperature(successful, exceptions);
			if(n>t)
			t=n;
		}
		return t;
	}
	exceptions.Add(new CommunicationException("temperature sensors"));
	successful=false;
	return 0;
}