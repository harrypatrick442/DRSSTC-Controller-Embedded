/*
* ICheck.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __ICheck_H__
#define __ICheck_H__
#include "PassFailCleanup.h"
#include "Exceptions.h"
class ICheck{
	public:virtual PassFailCleanup<Exceptions*> Check()=0;
};
#endif //__ICheck_H__
