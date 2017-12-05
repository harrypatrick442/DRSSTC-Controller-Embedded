/*
* EEPROM.cpp
*
* Created: 20/11/2017 21:00:58
*  Author: SoftwareEngineer
*/

#include <stdio.h>
#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
void eeprom_write_byte1(uint16_t addr, uint8_t data)
{
	cli();
	while(EECR & (1<<EEPE)) /*wait until previous write any*/
	;
	EEAR = addr;
	EEDR = data;
	EECR |= (1<<EEMPE);
	EECR |= (1<<EEPE);
	sei();
}

uint8_t eeprom_read_byte1(uint16_t addr)
{
	cli();
	while(EECR & (1<<EEPE))/*wait until previous write any*/
	;
	EEAR = addr;
	EECR |= (1<<EERE);
	uint8_t r=EEDR;
	sei();
	return r;
}

/*assumes s is a proper null terminated string*/
void eeprom_write_string(uint16_t addr, char *s)
{
	cli();
	while(*s)
	{
		eeprom_write_byte1(addr, *s );
		++s;
		++addr;
	}
	sei();
}

/* read a string of len characters maximum starting at addr.
* modify according to your need!
*/
void eeprom_read_string(uint16_t addr, char *s, int len)
{
	cli();
	while(len)
	{
		*s = eeprom_read_byte1(addr);
		if( *s == '\0' )
		return;
		--len;
		++s;
	}
	*s = '\0';
	sei();
	return;
}