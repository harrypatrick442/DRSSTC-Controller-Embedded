/*
* ISetTemperatureMax.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef _ISETTEMPERATUREMAX_H__
#define _ISETTEMPERATUREMAX_H__
#include <stdio.h>
class ISetTemperatureMax {
	public: virtual void SetTemperatureMax(uint8_t  a) = 0;//degrees c
};
#endif //_ISETTEMPERATUREMAX_H__
