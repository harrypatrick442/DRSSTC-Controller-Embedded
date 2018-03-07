/*
* Leds.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/



#include "Leds.h"
#include "Outputs.h"

Leds Leds:: _Singleton;
Leds& Leds::GetInstance(){
	return _Singleton;
}
Leds::Leds():backlight(new Led(this, &Leds::SetBacklightOn, &Leds::SetBacklightOff)), main(new Led(this, &Leds::SetMainOn, &Leds::SetMainOff))
{
backlight->TurnOff();
main->TurnOff();
}
Leds::Led::Led(Leds* leds, OnOff on, OnOff off):leds(leds), on(on), off(off){
	
}
void Leds::Led::TurnOn(){
	(leds->*on)();
}
void Leds::Led::TurnOff(){
	(leds->*off)();
}
void Leds::SetMainOn(){
Outputs::PD::_2::SetLow();
}
void Leds::SetMainOff(){
	Outputs::PD::_2::SetHigh();
}

void Leds::SetBacklightOn(){
	Outputs::PD::_3::SetHigh();
}
void Leds::SetBacklightOff(){
	Outputs::PD::_3::SetLow();
}
ILed* Leds::GetBacklight(){return backlight;}
ILed* Leds::GetMain(){return main;}
