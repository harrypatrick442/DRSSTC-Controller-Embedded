/*
* Leds.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/



#include "Leds.h"
#include "Outputs.h"



void Leds::Main::SetRed(){
	Outputs::PD::_2::SetLow();
	Outputs::PD::_3::SetLow();
	Outputs::PD::_4::SetHigh();
}
void Leds::Main::SetGreen(){
	Outputs::PD::_2::SetLow();
	Outputs::PD::_3::SetHigh();
	Outputs::PD::_4::SetLow();
}
void Leds::Main::SetBlue(){
	Outputs::PD::_2::SetHigh();
	Outputs::PD::_3::SetLow();
	Outputs::PD::_4::SetLow();
}
void Leds::Main::SetYellow(){
	Outputs::PD::_2::SetHigh();
	Outputs::PD::_3::SetHigh();
	Outputs::PD::_4::SetLow();
}
void Leds::Main::SetOrange(){
	Outputs::PD::_2::SetLow();
	Outputs::PD::_3::SetHigh();
	Outputs::PD::_4::SetHigh();
}
void Leds::Main::SetPurple(){
	Outputs::PD::_2::SetHigh();
	Outputs::PD::_3::SetLow();
	Outputs::PD::_4::SetHigh();
}
void Leds::Main::SetWhite(){
	Outputs::PD::_2::SetHigh();
	Outputs::PD::_3::SetHigh();
	Outputs::PD::_4::SetHigh();
}
void Leds::Main::SetOff(){
	Outputs::PD::_2::SetLow();
	Outputs::PD::_3::SetLow();
	Outputs::PD::_4::SetLow();
}