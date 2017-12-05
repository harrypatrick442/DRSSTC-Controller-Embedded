/* 
* SystemCheck.cpp
*
* Created: 22/11/2017 21:50:06
* Author: SoftwareEngineer
*/


#include "SystemCheck.h"

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
