/* 
* UART.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __MESSAGE_H__
#define __MESSAGE_H__
#include <stdlib.h>

class Message{
public:
const char* buffer;
unsigned int length;
Message(const char* bufferIn, unsigned int lengthIn);
~Message();
};
#endif //__MESSAGE_H__
