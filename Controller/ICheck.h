/*
* ICheck.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __ICheck_H__
#define __ICheck_H__
#include "Exceptions.h"
class ICheck{
	public:virtual void Check(bool& successful ,Exceptions& exceptions)=0;
};
#endif //__ICheck_H__
