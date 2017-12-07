/* 
* ISystemCheck.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __ISYSTEMCHECK_H__
#define __ISYSTEMCHECK_H__
#include "Exceptions.h"
class ISystemCheck {
	public: virtual void Check(bool& successful, Exceptions& exceptions) = 0;
};
#endif //__ISYSTEMCHECK_H__
