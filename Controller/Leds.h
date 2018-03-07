/*
* Leds.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __LEDS_H__
#define __LEDS_H__
#include "ILed.h"
class Leds
{
	//variables
	public:
	class Led:public ILed{
		public:
		typedef void (Leds::*OnOff)();
		OnOff on;
		OnOff off;
		private:
		Leds* leds;
		public:
		Led(Leds* leds, OnOff on, OnOff off);
		void TurnOn();
		void TurnOff();
	};
	private:
	static Leds _Singleton;
	Led*backlight;
	Led* main;
	//methods
	private:
	Leds();
	public:
	static Leds& GetInstance();
	void SetMainOn();
	void SetMainOff();
	void SetBacklightOn();
	void SetBacklightOff();
	ILed* GetBacklight();
	ILed* GetMain();
	protected:
	private:
}; //Leds

#endif //__LEDS_H__
