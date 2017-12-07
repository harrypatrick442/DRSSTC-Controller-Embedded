/*
* Fans.h
*
* Created: 08/10/2017 12:37:23
* Author: SoftwareEngineer
*/


#ifndef __TC654_H__
#define __TC654_H__
#include "IGetFanInfo.h"
#include "IFans.h"
#include "Exception.h"

class TC654
{
	//variables
	public:
	protected:
	private:
	const char ADDRESS_WRITE = 0x36;
	const char ADDRESS_READ=0x37;
	const char RPM1_ADDRESS = 0x00;
	const char RPM2_ADDRESS=0x01;
	const char FAN_FAULT1_ADDRESS=0x02;
	const char FAN_FAULT2_ADDRESS=0x03;
	const char CONFIG_ADDRESS=0x04;
	const char STATUS_ADDRESS=0x05;
	const char DUTY_CYCLE_ADDRESS=0x06;
	const char MFR_ID_ADDRESS=0x07;
	const char VER_ID_ADDRESS=0x08;
	unsigned char F1PPR;
	unsigned char F2PPR;
	//functions
	public:
	class Status{
		private:
		char value;
		public:
		Status(char value);
		bool GetF1F();
		bool GetF2F();
		bool GetR1CO();
		bool GetR2CO();
	};
	class Fan:public IGetFanInfo{
		public:
		const char* name;
		TC654* tc654;
		typedef unsigned char (TC654::*CallbackGetRPM)(bool& successful);
		typedef PassFailCleanup<Exception*>(TC654::*CallbackCheck)();
		CallbackGetRPM callbackGetRPM;
		CallbackCheck callbackCheck;
		Fan(TC654* tc654, CallbackGetRPM callbackGetRRPM, CallbackCheck callbackCheck, char* name);
		const char* GetName();
		uint16_t GetFanSpeed(bool& successful);
		PassFailCleanup<Exceptions*> Check();
	};
	Fan fan1;
	Fan fan2;
	TC654(char F1PPR, char F2PPR);
	unsigned char GetRPM1(bool& successful);
	unsigned char GetRPM2(bool& successful);
	unsigned char GetFanFault1(bool& successful);
	unsigned char GetFanFault2(bool& successful);
	void SetFanFault2(bool& successful, unsigned char value);
	void SetFanFault1(bool& successful, unsigned char value);
	unsigned char GetDutyCycle(bool& successful);
	void SetDutyCycle(bool& successful, unsigned char value);
	Status GetStatus(bool& successful);
	IGetFanInfo* GetIGetFan1Info();
	IGetFanInfo* GetIGetFan2Info();
	~TC654();

	protected:
	private:
	void WriteConfigurationRegister(bool& successful, char configuration);
	void WriteRegister(bool& successful, char address, char value);
	unsigned char ReadConfigurationRegister(bool& successful);
	unsigned char ReadRegister(bool& successful, char address);
	void Configure(bool& successful);

};

#endif
