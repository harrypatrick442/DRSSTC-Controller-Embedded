/* 
* IGetErrors.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __IGETERRORS_H__
#define __IGETERRORS_H__
#include "ErrorMessages.h"
class IGetErrors{ 
public:virtual ErrorMessages* GetErrors()=0;
};
#endif //__IGETERRORS_H__
