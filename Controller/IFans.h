/* 
* IFans.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __IFANS_H__
#define __IFANS_H__
#include "IGetExceptions.h"
#include "Exceptions.h"
#include <stdbool.h>
class          IFans { 
public:virtual  void GetFansWorkingCorrectly(bool& successful,  Exceptions& exceptions)=0;
};
#endif //__IFANS_H__
