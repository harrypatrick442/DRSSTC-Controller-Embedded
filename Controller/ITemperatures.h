/*
* ITemperatures.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef _ITEMPERATURES_H__
#define _ITEMPERATURES_H__
#include <stdio.h>
#include "Exceptions.h"
class ITemperatures {
	public: virtual int8_t GetMaxTemperature(bool& successful, Exceptions& exceptions) = 0;//degrees c
};
#endif //_ITEMPERATURES_H__
