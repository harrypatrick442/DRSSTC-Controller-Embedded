/* 
* Settings.h
*
* Created: 20/11/2017 21:01:43
* Author: SoftwareEngineer
*/


#ifndef __SENDER_H__
#define __SENDER_H__
#include "ISendMessage.h"
#include "ISendRGBC.h"
#include "RGBC.h"
class Sender:public ISendRGBC
{
private:
ISendMessage* iSendMessage;
public:
Sender(ISendMessage* iSendMessage);
void SendRGBC(RGBC rgbc);
};

#endif //__SETTINGS_H__
