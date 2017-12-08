/* 
* SystemCheck.cpp
*
* Created: 22/11/2017 21:50:06
* Author: SoftwareEngineer
*/


#include "SystemCheck.h"
#include "UART.h"
#include <stdbool.h>

SystemCheck SystemCheck:: _Singleton;
SystemCheck& SystemCheck::GetInstance(){
	static bool initialized=false;
	if(!initialized)
	{
		_Singleton.Initialize();
		initialized=true;
	}
	return _Singleton;
}
void SystemCheck::Initialize(){

}
void SystemCheck::SetInterfaces(ITemperatures* iTemperatures, IGetTemperatureMax *  iGetTemperatureMax, IFans* iFans){
	this->iTemperatures=iTemperatures;
	this->iGetTemperatureMax=iGetTemperatureMax;
	this->iFans = iFans;
}
void SystemCheck::Check(bool& successful, Exceptions&exceptions){
	int8_t temperature=iTemperatures->GetMaxTemperature(successful, exceptions	 );
	if(successful){
	iFans->GetFansWorkingCorrectly(successful, exceptions);
	}
}
