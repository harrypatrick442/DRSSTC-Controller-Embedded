/*
* Outputs.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include <avr/io.h>
#include "Outputs.h"

// default constructor
Outputs::Outputs()
{
} //Outputs

// default destructor
Outputs::~Outputs()
{
} //~Outputs
void Outputs::Initialize(){
	//DDRB = 0x20;
	DDRD = DDRD | 0x0C ;
	
	//DDRC = DDRC	&0xff;
	//PORTC =0x00;
	//DDRC = DDRC | 0xf;
	//PORTC = 0X00;
}
void Outputs::PD::_2::SetHigh(){
	PORTD = PORTD|0x04;

}
void Outputs::PD::_2::SetLow(){
	PORTD= PORTD&0xFB;
}
void Outputs::PD::_3::SetHigh(){
	PORTD = PORTD|0x08;

}
void Outputs::PD::_3::SetLow(){
	PORTD= PORTD&0xF7;
}