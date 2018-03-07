/*
* ICheck.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __ICOLOURSENSOR_H__
#define __ICOLOURSENSOR_H__
#include "ISetFastMode.h"
#include "IGetRGBC.h"
class IColourSensor:public ISetFastMode, public IGetRGBC{
};
#endif
