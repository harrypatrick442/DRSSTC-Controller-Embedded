/* 
* IFans.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __IFANS_H__
#define __IFANS_H__
#include "IGetExceptions.h"
#include "PassFailCleanup.h"
#include "Exceptions.h"
class          IFans:   public IGetExceptions { 
public:virtual  PassFailCleanup<Exceptions*> GetFansWorkingCorrectly()=0;
};
#endif //__IFANS_H__
