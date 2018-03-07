/* 
* IGetMessages.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __IGETMESSAGES_H__
#define __IGETMESSAGES_H__
#include "Messages.h"
class IGetMessages {
	public: virtual Messages* GetMessages() = 0;
};
#endif //__IGETMESSAGES_H__
