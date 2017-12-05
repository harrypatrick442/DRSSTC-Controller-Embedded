/* 
* IGetTemperatureInfo.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __IGETTEMPERATUREINFO_H__
#define __IGETTEMPERATUREINFO_H__
#include "IGetTemperature.h"
#include "IGetName.h"
class IGetTemperatureInfo:public IGetTemperature, public IGetName{ 
};
#endif //__IGETTEMPERATUREINFO_H__
