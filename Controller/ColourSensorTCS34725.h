/*
* ColourSensorTCS34725.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __COLOUR_SENSOR_TCS34725_H__
#define __COLOUR_SENSOR_TCS34725_H__

#include "Exception.h"
#include "Exceptions.h"
#include "IGetMessages.h"
#include "TCS34725.h"
#include "ISendRGBC.h"
#include "IColourSensor.h"
#include "ISubscriptionRunner.h"
#include "ILed.h"
class  ColourSensorTCS34725:public IColourSensor, public ISubscriptionRunnable
{
	//variables
	public:
	typedef enum State{LightingUp, Running, Stopping};
	protected:
	private:
	State state;
	bool fast;
	TCS34725* tcs34725;
	ISendRGBC* iSendRGBC;
	ILed* iLedSource;
	ISubscriptionRunner* iSubscriptionRunner;
	//functions
	public:
	ColourSensorTCS34725(TCS34725* tcs34725, ISendRGBC* iSendRGBC, ISubscriptionRunner* iSubscriptionRunner, ILed* iLedSource);
	~ColourSensorTCS34725();
	void Run();
	void SetFastMode(bool fast, bool& successful, Exceptions&exceptions);
	RGBC GetRGBC(bool& successful , Exceptions& exceptions);
	protected:
	private:
	void _Run();
}; //Outputs

#endif
