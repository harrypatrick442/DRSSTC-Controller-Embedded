/* 
* UART.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __UART_H__
#define __UART_H__
#include <stdlib.h>
#include "Messages.h"
#include "IGetMessages.h"
#include "ISendMessage.h"
#define UART_BUFFER_SIZE 64
#define UART_N_BUFFERS 4

class UART:public ISendMessage, public IGetMessages
{
//variables
public:
protected:
private:
static UART _Singleton;
volatile int bufferIndexes[UART_N_BUFFERS];
volatile char buffer[UART_N_BUFFERS][UART_BUFFER_SIZE] ;
volatile char nBuffer;
volatile bool overflowedCurrentBuffer;
volatile bool overflowedBuffers;
 void Initialize ();
//functions
public:
 static  UART& GetInstance()  ;
 Messages* GetMessages();
 void Incoming();
 void SendMessage(const char* message, unsigned int length);
 void Send(char);
void operator=(UART const&) = delete; // Don't implement
protected:
public:

private:
UART(){}
}; //UART

#endif //__UART_H__
