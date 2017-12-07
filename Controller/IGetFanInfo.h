/* 
* IGetFanInfo.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __IGETFANINFO_H__
#define __IGETFANINFO_H__
#include "IGetFanSpeed.h"
#include "ICheck.h"
#include "IGetName.h"
class IGetFanInfo:public IGetFanSpeed, public IGetName, public ICheck{ 
};
#endif //__IGETFANINFO_H__
