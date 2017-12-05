/**********************************************
Filename 	: uart0.h
Target   	: Atmega 128
CPU Freq 	: 16Mhz
Description 	: Library of UART0 functions
Author    	: Prashant Mehta
***********************************************/
#include<avr/io.h>
#define USART_BAUDRATE 9200
#define UBRR_VALUE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
void uart0_init(void);										
void UART0_Transmit_char(char char_data);
char UART0_Receive_char(void);
void UART0_Transmit_num(unsigned int num_data);
void UART0_Transmit_string(char *str_data);
unsigned int UART0_Receive_num(void);
char *UART0_Receive_string(void);


void uart0_init(void)
{
/* uart1(polling mode),8-bit data,1 STOP BIT, 9600 baud rate, no-parity*/
	UBRR0H = (uint8_t)(UBRR_VALUE >>8);
	UBRR0L = (uint8_t)UBRR_VALUE;
	
	UCSR0A=0X0;
	UCSR0B=0X98;
	UCSR0C=0X06;
}



void UART0_Transmit_char(char char_data)		/*Function to transmit character data*/
{
	while((UCSR0A & 0X20)!=0X20); 			/* wait till data register is empty*/
	UDR0=char_data;
}


char UART0_Receive_char(void)				/*Function to receive character data*/
{
	while((UCSR0A & 0X80)!=0X80);			/*wait till reciption is over*/
	return UDR0;
}


void UART0_Transmit_num(unsigned int num_data)/*Function to transmit numeric data*/
{
	int a[20];
	int i=0;
	if(num_data==0) UART_Transmit_char('0');
	while(num_data>0)
   {
        a[i]=(num_data%10) | 0x30;			/* separating digits of num, storing it into array,
											OR it with 0x30 to convert it into ASCII character */
        num_data=num_data/10;
        i++;
   }
   i=i-1;
	while(i>=0)
	{
		UART0_Transmit_char((char)a[i]);	/*Type cast a[i] into character and pass it into transmit_char funcion*/
		i--;
	}
}


void UART0_Transmit_string(char *str_data)	/*Function to transmit string*/
{
	while(*str_data!='\0')
	{
	UART0_Transmit_char(*str_data);
	str_data++;
	}
}

unsigned int UART0_Receive_num(void)		 /*Function to receive numeric data*/

{
	/* for receiving numeric data, first take one by one characters into an array,
	convert it from ASCII to numeric value by AND with 0x0f,,
	and make a complete number from its digits*/
	unsigned int b[5];
	char t;
	int j;
	int x=1;
	int k=0;
	unsigned int num=0;
	while((t=UART0_Receive_char())!=13)				
	{
		
	b[k] = (unsigned int)t & 0x000F;
	k++;
	}
	
	k=k-1;
	while(k>=0)
	{
	num=num+(b[k]*x);
	x=x*10;
	k--;
	}
	return num;
}

char *UART0_Receive_string(void)			/*Function to receive a string*/
{
	char *q;
	char str[20];
	int count=0;
	int j;
	char s;
	while((s=UART0_Receive_char())!=13)				
	{
	str[count] = s;
	count++;
	}
	str[count]='\0';
	q=&str;
	return q;
	
}
