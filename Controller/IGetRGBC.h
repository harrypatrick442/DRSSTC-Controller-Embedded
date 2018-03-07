/*
* ICheck.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __IGetRGB_H__
#define __IGetRGB_H__
#include "Exceptions.h"
#include "RGBC.h"
class IGetRGBC{
	public:virtual RGBC GetRGBC(bool& successful ,Exceptions& exceptions)=0;
};
#endif //__IGetRGB_H__
