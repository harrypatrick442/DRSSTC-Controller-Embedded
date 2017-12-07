/* 
* IGetTemperature.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __IGETTEMPERATURE_H__
#define __IGETTEMPERATURE_H__
#include <stdio.h>
#include "Exceptions.h"
class IGetTemperature{
	public: virtual int8_t GetTemperature(bool& successful, Exceptions& exceptions)=0;
};
#endif //__IGETTEMPERATURE_H__
