/*
* ICheck.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __ISendRGB_H__
#define __ISendRGB_H__
#include "RGBC.h"
class ISendRGBC{
	public:virtual void SendRGBC(RGBC rgbc)=0;
};
#endif //__IGetRGB_H__
