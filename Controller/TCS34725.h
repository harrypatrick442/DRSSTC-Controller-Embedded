/*
* TCS34725.h
*
* Created: 08/10/2017 12:37:23
* Author: SoftwareEngineer
*/


#ifndef __TCS34725_H__
#define __TCS34725_H__
#include "IGetRGBC.h"
#include "RGBC.h"
#include "Exceptions.h"


class TCS34725:public IGetRGBC
{
	//variables
	public:
	protected:
	private:
	const unsigned char ADDRESS_WRITE = (0x29<<1);
	const unsigned char ADDRESS_READ=(0x29<<1)|0x01;
	const unsigned char ENABLE_ADDRESS = 0x00;
	const unsigned char ATIME_ADDRESS = 0x01;
	const unsigned char WTIME_ADDRESS = 0x03;
	const unsigned char AILTL_ADDRESS = 0x04;
	const unsigned char AILTH_ADDRESS = 0x05;
	const unsigned char AIHTL_ADDRESS = 0x06;
	const unsigned char  AIHTh_ADDRESS= 0x07;
	const unsigned char PERS_ADDRESS = 0x0C;
	const unsigned char CONFIG_ADDRESS = 0X0D;
	const unsigned char CONTROL_ADDRESS = 0X0F;
	const unsigned char ID_ADDRESS = 0x12;
	const unsigned char STATUS_ADDRESS = 0x13;
	const unsigned char CDATAL_ADDRESS = 0x14;
	const unsigned char CDATAH_ADDRESS = 0x15;
	const unsigned char RDATAL_ADDRESS = 0x16;
	const unsigned char RDATAH_ADDRESS = 0x17;
	const unsigned char GDATAL_ADDRESS =0x18;
	const unsigned char GDATAH_ADDRESS = 0x19;
	const unsigned char BDATAL_ADDRESS = 0x1A;
	const unsigned char BDATAH_ADDRESS = 0x1B;
	const   char* name;
	bool configured = false;
	unsigned char aTime;
	unsigned char wTime;
	bool wLong;
	unsigned char aPers;
	unsigned char aGain;
	//functions
	public:
	TCS34725(const char* name, unsigned char aTime, unsigned char wTime, bool wLong, unsigned char aGain, unsigned char aPers);
	~TCS34725();
	RGBC GetRGBC(bool&successful, Exceptions&exceptions);
	protected:
	private:

	void WriteEnableRegister(bool& successful, bool AIEN, bool WEN, bool AEN, bool PON);
	void WriteRGBCTimingRegister(bool& successful, unsigned char ATIME);
	void WriteWaitTimeRegister(bool& successful, unsigned char WTIME);
	void WritePersistenceRegister(bool& successful, unsigned char APERS);
	void WriteConfigurationRegister(bool& successful, bool WLONG);
	void WriteControlRegister(bool&successful, unsigned char AGAIN);

	void WriteRegister(bool& successful, unsigned char address, unsigned char value);
	unsigned char ReadConfigurationRegister(bool& successful);
	unsigned char ReadRegister(bool& successful, unsigned char address);
	unsigned char* ReadRegisterIncrement(bool& successful, unsigned char address, unsigned char& nBytes);
	void ConfigureIfNotDone(bool& successful, Exceptions& exceptions);
};

#endif
