/* 
* SystemCheck.cpp
*
* Created: 22/11/2017 21:50:06
* Author: SoftwareEngineer
*/


#include "SystemCheck.h"
#include "UART.h"
#include <stdbool.h>
#include <cstddef>

SystemCheck SystemCheck:: _Singleton;
SystemCheck& SystemCheck::GetInstance(){
	static bool initialized=false;
	if(!initialized)
	{
		initialized=true;
	}
	return _Singleton;
}
void SystemCheck::Initialize(){

}
void SystemCheck::SetInterfaces(){
}
void SystemCheck::Check(bool& successful, Exceptions&exceptions){
	
}
