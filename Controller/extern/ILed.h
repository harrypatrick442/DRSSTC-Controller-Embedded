/* 
* ISendMessage.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __ISENDMESSAGE_H__
#define __ISENDMESSAGE_H__
class ISendMessage {
	public: virtual void SendMessage(const char* buffer, unsigned int length) = 0;
};
#endif //__ISENDMESSAGE_H__
