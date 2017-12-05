/* 
* Settings.h
*
* Created: 20/11/2017 21:01:43
* Author: SoftwareEngineer
*/


#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include "IGetTemperatureMax.h"
#include "ISetTemperatureMax.h"
#include "IGetPower.h"
#include "ISetPower.h"
#define TEMPERATURE_MAX_MAX 125
#define TEMPERTURE_MAX_MIN 40
#define POWER_MIN 30
#define POWER_MAX 1500
class Settings:public  IGetTemperatureMax, public  ISetTemperatureMax, public  IGetPower, public  ISetPower
{
//variables
public:
protected:
private:
uint8_t temperatureMax=119;
uint16_t power=10;
static Settings _Singleton;

//functions
public:
static  Settings& GetInstance();
uint8_t GetTemperatureMax();//degrees c
void SetTemperatureMax(uint8_t t);//degrees c
uint16_t GetPower();//watts
void SetPower(uint16_t t);//watts
protected:
private:
void Initialize ();
void CapTemperatureMax(uint8_t& a);
void CapPower(uint16_t& a);
void operator=(Settings const&) = delete; // Don't implement

}; //Settings

#endif //__SETTINGS_H__
