/*
* Fans.h
*
* Created: 08/10/2017 12:37:23
* Author: SoftwareEngineer
*/


#ifndef __Fans_H__
#define __Fans_H__
#include "IGetFanInfo.h"
#include "IFans.h"

class TC654:
public IGetFanInfo
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
	Fan fan1;
	Fan fan2;	//functions
	public:
	class Status{
		public:
		Status(char value);
		bool GetF1F();
		bool GetF2F();
		bool GetR1CO();
		bool GetR2CO();
	}
	class Fan:public IGetFanInfo{
		public:
		const char* name;
		typedef unsigned char (CallbackGetRPM*)(bool& successful);
		CallbackGetRPM callbackGetRPM;
		Fan(CallbackGetRPM callbackGetRRPM, char name);
		const char* GetName();
		uint16_t GetFanSpeed(bool& successful);
	};
	TC654::TC654(char F1PPR, char F2PPR);
	unsigned char GetRPM1(bool& successful);
	unsigned char GetRPM2(bool& successful);
	unsigned char GetFanFault1(bool& successful);
	unsigned char GetFanFault2(bool& successful);
	void SetFanFault2(bool& successful, unsigned char value);
	void SetFanFault1(bool& successful, unsigned char value);
	unsigned char GetDutyCycle(bool& successful);
	void SetDutyCycle(bool& successful, unsigned char value);
	Status GetStatus(bool& successful);
	IGetFanInfo& GetIGetFan1Info();
	IGetFanInfo& GetIGetFan2Info();
	~TC654();

	protected:
	private:
	void WriteConfigurationRegister(bool& successful, char configuration);
	void WriteRegister(bool& successful, char address, char value);
	void ReadConfigurationRegister(bool& successful);
	void ReadRegister(bool& successful, char address);
	void Configure(bool& successful);

};

#endif
