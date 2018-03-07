/*
* ICheck.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __ISetFastMode_H__
#define __ISetFastMode_H__
#include "Exceptions.h"
class ISetFastMode{
	public:virtual void SetFastMode(bool fast, bool& successful, Exceptions& exceptions)=0;
};
#endif //__ISetFastMode_H__
