/* 
* LM75.h
*
* Created: 08/10/2017 12:37:23
* Author: SoftwareEngineer
*/


#ifndef __LM75_H__
#define __LM75_H__
#include "i2cmaster.h"
#include "IGetTemperatureInfo.h"
#include "Stopwatch.h"





class LM75:public IGetTemperatureInfo
{
//variables
public:
protected:
private:
const char TEMPERATURE_ADDRESS = 0x00;
const char CONFIGURATION_ADDRESS = 0x01;
const char THYST_ADDRESS = 0x02;
const char TOS_ADDRESS = 0X03;
const char* name;
	unsigned char addressRead;
	unsigned char addressWrite;

//functions
public:
	LM75(char address, char* name);
	int8_t GetTemperature(bool& successful);
	const char* GetName();
	~LM75();
protected:
private:
	LM75( const LM75 &c );
	LM75& operator=( const LM75 &c );

}; //LM75

#endif //__LM75_H__
