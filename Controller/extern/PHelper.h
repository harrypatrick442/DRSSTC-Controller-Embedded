/* 
* Stopwatch.h
*
* Created: 08/10/2017 16:33:17
* Author: SoftwareEngineer
*/


#ifndef __PHELPER_H__
#define __PHELPER_H__


#include "Cleanup.h"
#include "ISendMessage.h"
class PHelper
{
public:
static Cleanup<const char*> Marshal(const char* p);
static void SendP(const char* str, ISendMessage* iSendMessage);
}; 

#endif 
