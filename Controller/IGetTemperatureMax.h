/*
* IGetTemperatureMax.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef _IGETTEMPERATUREMAX_H__
#define _IGETTEMPERATUREMAX_H__
#include <stdio.h>
class IGetTemperatureMax {
	public: virtual uint8_t GetTemperatureMax() = 0;//degrees c
};
#endif //_IGETTEMPERATUREMAX_H__
