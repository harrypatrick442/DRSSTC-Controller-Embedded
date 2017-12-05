/*
* LM75.cpp
*
* Created: 08/10/2017 12:37:23
* Author: SoftwareEngineer
*/
#include "i2cmaster.h"
#include "LM75.h"
#include <avr/interrupt.h>
// default constructor
LM75::LM75(char address, char* name):name(name)
{
	char shifted = (address<<1);
	addressWrite =0x90|(shifted&0x0e);
	addressRead =0x91|(shifted&0x0e);
} //LM75
const char* LM75::GetName(){
	return name;
}
int8_t LM75::GetTemperature(bool& successful){
	i2c_start_wait(addressWrite);
	char r=i2c_write(TEMPERATURE_ADDRESS);
	i2c_stop();
	if(r!=0){
		successful=false;
	}

	i2c_start_wait(addressRead);
	char most = i2c_readAck();
	char least = i2c_readAck();
	sei();
	return static_cast<int8_t>(most);
	i2c_stop();
	return 0;
}
// default destructor
LM75::~LM75()
{
} //~LM75
