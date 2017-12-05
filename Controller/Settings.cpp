/*
* Settings.cpp
*
* Created: 20/11/2017 21:01:43
* Author: SoftwareEngineer
*/


#include "Settings.h"
#include "EEPROM.h"
#include <avr/eeprom.h>

uint8_t EEMEM  ADDRESS_TEMPERATURE_MAX;
uint16_t EEMEM  ADDRESS_POWER;
Settings Settings:: _Singleton;
Settings& Settings::GetInstance(){
	static bool initialized=false;
	if(!initialized)
	{
		_Singleton.Initialize();
		initialized=true;
	}
	return _Singleton;
}
void Settings::Initialize(){
	temperatureMax= eeprom_read_byte(&ADDRESS_TEMPERATURE_MAX);
	CapTemperatureMax(temperatureMax);
	
	uint16_t a= eeprom_read_word(&ADDRESS_POWER);
	CapPower(a);
	power=a;
}
void Settings::CapTemperatureMax(uint8_t& a){
	if(a>TEMPERATURE_MAX_MAX)
		a=TEMPERATURE_MAX_MAX;
	else
		if(a<TEMPERTURE_MAX_MIN)
			a=TEMPERTURE_MAX_MIN;
}	
void Settings::CapPower(uint16_t& a){
	
	if(a>POWER_MAX)
		a=POWER_MAX;
	else
		if(a<POWER_MIN)
			a=POWER_MIN;
}
uint8_t Settings::GetTemperatureMax(){
	return temperatureMax;
}
void Settings::SetTemperatureMax(uint8_t a){
	CapTemperatureMax(a);
	temperatureMax=a;
	eeprom_write_byte(&ADDRESS_TEMPERATURE_MAX, a);
}
uint16_t Settings::GetPower(){
	return power;
}
void Settings::SetPower(uint16_t a){
	CapPower(a);
	eeprom_write_word(&ADDRESS_POWER, a);
}
