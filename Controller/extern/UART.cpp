/*
* UART.cpp
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#include<avr/io.h>
#include "UART.h"
#include <avr/interrupt.h>
#define BAUD 9600
#define F_CPU 8000000UL
#include <util/setbaud.h>

 UART UART:: _Singleton;
  UART& UART::GetInstance(){
 static bool initialized=false;
 if(!initialized)
 {
 _Singleton.Initialize();
 initialized=true;
 }
	return _Singleton;
}
 void UART::Initialize ()
{
	//volatile int bufferIndexes[UART_N_BUFFERS];
	//volatile char buffer[UART_N_BUFFERS][UART_BUFFER_SIZE] ;
	
	nBuffer=0;
	overflowedCurrentBuffer=false;
	overflowedBuffers=false;
	DDRD =DDRD&0xFE;
	DDRD = DDRD | 0x2;
//PORTD=PORTD&0x1;
	for(char i=0; i<UART_N_BUFFERS; i++)
	{
		bufferIndexes[i]=0;
	}
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	#if USE_U2X
	UCSR0A |= (1<<U2X0);
	#else
	UCSR0A &= ~(1<<U2X0);
	#endif
	/*Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0)|( 1<<RXCIE0);

	UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);

	sei();
}

void UART::Incoming(){
	unsigned char data = UDR0;
	if(    data==13||data==10   )
	{
		if(bufferIndexes[nBuffer]!=0)
		{
			if(!overflowedCurrentBuffer)
			{
				if(nBuffer<UART_N_BUFFERS-1)
				{
					nBuffer++;
					bufferIndexes[nBuffer]=0;
					overflowedCurrentBuffer=false;

				}
				else
				{
					for(char i=0; i<UART_N_BUFFERS; i++)
					{
						if(bufferIndexes[i]==0)
						{
							nBuffer=i;
							overflowedCurrentBuffer=false;
							overflowedBuffers=false;
							return;
						}
					}
					overflowedBuffers=true;
				}
			}
			else
			{
				overflowedCurrentBuffer=false;
				bufferIndexes[nBuffer]=0;
			}
		}
	}
	else
	{
		if(!overflowedCurrentBuffer&&!overflowedBuffers)
		{
			int bufferIndex=bufferIndexes[nBuffer];
			if(bufferIndex>=UART_BUFFER_SIZE)
			{
				overflowedCurrentBuffer=true;
			}
			else{
					buffer[nBuffer][bufferIndex]=data;
					bufferIndexes[nBuffer]=bufferIndex+1;
				}
			}
		}
	}
	Messages* UART::GetMessages(){
		char tempMessagesIndex=0;
		Message* tempMessages [UART_N_BUFFERS];
		for(char i=0; i<UART_N_BUFFERS; i++)
		{
			if(i!=nBuffer){
				if(bufferIndexes[i]>0){

				unsigned int length = bufferIndexes[i];
					char* buf = new char[ length+1];
					for (int j = 0; j < length; j++)
					buf[j] = (char)buffer[i][j];
					buf[length]='\0';
					tempMessages[tempMessagesIndex]=new Message(buf, length);
					tempMessagesIndex++;
					bufferIndexes[i]=0;
					overflowedBuffers=false;
				}
			}
		}
		Messages* m = (tempMessagesIndex>0)? new Messages(tempMessages, tempMessagesIndex):NULL;
		return m;
}
	ISR(USART_RX_vect){
		cli();
		UART::GetInstance().Incoming();
		sei();
	}
	void UART::Send(char message){
		while((UCSR0A & 0X20)!=0X20); 		/* wait till data register is empty*/
		UDR0=message;
	}
	void UART::SendMessage(const char* message, unsigned int length){
		for(unsigned int i=0; i<length; i++)
		Send(*(message+i));
	}