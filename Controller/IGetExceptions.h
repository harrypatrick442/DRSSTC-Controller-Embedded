/* 
* IGetExceptions.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __IGETEXCEPTIONS_H__	
#define __IGETEXCEPTIONS_H__
#include "Exceptions.h"
class IGetExceptions{ 
public:virtual Exceptions* GetExceptions()=0;
};
#endif //__IGETEXCEPTIONS_H__
