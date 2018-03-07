/*
* TC654.cpp
*
* Created: 08/10/2017 12:37:23
* Author: SoftwareEngineer
*/
#include "i2cmaster.h"
#include "TCS34725.h"
#include "CommunicationException.h"
#include "Exceptions.h"
#include "UART.h"
#include "TCS34725Exception.h"
#include "Leds.h"
#include<stdio.h>
// default constructor
TCS34725::TCS34725(const char* name, unsigned char aTime, unsigned char wTime, bool wLong, unsigned char aGain, unsigned char aPers)
:aTime(aTime), wLong(wLong), wTime(wTime), aGain(aGain), aPers(aPers), name(name)
{
	Exceptions exceptions;
	bool successful=true;
	ConfigureIfNotDone(successful, exceptions);
}
RGBC TCS34725::GetRGBC(bool& successful, Exceptions&exceptions){
	
	ConfigureIfNotDone(successful, exceptions);
	if(successful){
		unsigned char nBytes=8;
		unsigned char* bytes = ReadRegisterIncrement(successful, CDATAL_ADDRESS, nBytes);
		if(successful&&bytes != NULL){
			uint16_t h=(uint16_t)bytes[1];
			uint16_t c =(h<<8)| bytes[0];
			h=(uint16_t)bytes[3];
			uint16_t r = (h<<8)| bytes[2];
			h=(uint16_t)bytes[5];
			uint16_t g = (h<<8)| bytes[4];
			h=(uint16_t)bytes[7];
			uint16_t b = (h<<8)| bytes[6];
			free(bytes);
			return RGBC(r, g, b, c);
		}
		exceptions.Add(new TCS34725Exception(name, "Reading RGBC failed", TCS34725Exception::Communication));
	}
	return RGBC();
}
void TCS34725::WriteEnableRegister(bool& successful, bool aIEN, bool wEN, bool aEN, bool pON){
	char configuration = (aIEN?0x10:0x00)+(wEN?0x08:0x00)+(aEN?0x02:0x00)+(pON?0x01:0x00);
	WriteRegister(successful, ENABLE_ADDRESS, configuration);
}
void TCS34725::WriteRGBCTimingRegister(bool& successful, unsigned char aTIME){
	WriteRegister(successful, ATIME_ADDRESS, aTIME);
}
void TCS34725::WriteWaitTimeRegister(bool& successful, unsigned char wTIME){
	WriteRegister(successful, WTIME_ADDRESS, wTIME);
}
void TCS34725::WritePersistenceRegister(bool& successful, unsigned char aPERS){
	if(aPERS>15)aPERS=15;
	WriteRegister(successful, PERS_ADDRESS, aPERS);
}
void TCS34725:: WriteConfigurationRegister(bool& successful, bool wLONG){
	char configuration = (wLONG?0x02:0x00);
	WriteRegister(successful, CONFIG_ADDRESS, configuration);
}
void TCS34725::WriteControlRegister(bool&successful, unsigned char aGAIN){
	if(aGAIN>3)aGAIN=3;
	WriteRegister(successful, CONTROL_ADDRESS, aGAIN);
}

void TCS34725::WriteRegister(bool& successful, unsigned char address, unsigned char value){
	char command = 0x80|address;
	i2c_start_wait(ADDRESS_WRITE);
	char r=i2c_write(command);
	if(r!=0){
		successful=false;
		i2c_stop();
		return;
	}
	r=i2c_write(value);
	i2c_stop();
	if(r!=0){
		successful=false;
	}
}
unsigned char TCS34725::ReadConfigurationRegister(bool& successful){
	return ReadRegister(successful, CONFIG_ADDRESS);
}
unsigned char TCS34725::ReadRegister(bool& successful, unsigned char address){
	char command = 0x80|address;
	i2c_start_wait(ADDRESS_WRITE);
	char r=i2c_write(command);
	if(r==0){
		r=i2c_write(ADDRESS_READ);
		if(r==0){
			r = i2c_readAck();
			i2c_stop();
			return r;
		}
	}
	//i2c_start_wait(ADDRESS_READ);
	successful=false;
	i2c_stop();
	return 0;
}
unsigned char* TCS34725::ReadRegisterIncrement(bool& successful, unsigned char address, unsigned char& nBytes){
	unsigned char command = 0xA0|address;
	i2c_start_wait(ADDRESS_WRITE);
	unsigned char r=i2c_write(command);
	if(r==0){
		r=i2c_rep_start(ADDRESS_READ);
		if(r==0){
			unsigned char* bytes = (unsigned char*) malloc(nBytes);
			if(bytes!=NULL){
				for(char i=0; i<nBytes; i++)
				bytes[i]=i2c_readAck();
				i2c_stop();
				return bytes;
			}
		}
	}
	successful=false;
	i2c_stop();
	nBytes=0;
	return NULL;
}
void TCS34725::ConfigureIfNotDone(bool& successful, Exceptions& exceptions){
	if(!configured){
		WriteEnableRegister(successful, false, true, true, true);
		if(!successful)
		{
			exceptions.Add(new TCS34725Exception(name, "Setting enable register failed", TCS34725Exception::Configuration));
			return;
		}
		WriteRGBCTimingRegister(successful, aTime);
		if(!successful)
		{
			exceptions.Add(new TCS34725Exception(name, "Setting RGBC timing register failed", TCS34725Exception::Configuration));
			return;
		}
		WriteWaitTimeRegister(successful, wTime);
		if(!successful)
		{
			exceptions.Add(new TCS34725Exception(name, "Setting wait time register failed", TCS34725Exception::Configuration));
			return;
		}
		WriteConfigurationRegister(successful, wLong);
		if(!successful)
		{
			exceptions.Add(new TCS34725Exception(name, "Setting   wait long register failed", TCS34725Exception::Configuration));
						return;
		}
		WriteControlRegister(successful, aGain);
		if(!successful)
		{
			exceptions.Add(new TCS34725Exception(name, "Setting analogue gain register failed", TCS34725Exception::Configuration));
						return;
		}
		WritePersistenceRegister(successful, aPers);
		if(!successful)
		{
			exceptions.Add(new TCS34725Exception(name, "Setting integration persistence register failed", TCS34725Exception::Configuration));
					return;
					}
		configured=true;
	}
}

TCS34725::~TCS34725()
{
}
