/*
* LM75.cpp
*
* Created: 08/10/2017 12:37:23
* Author: SoftwareEngineer
*/
#include "i2cmaster.h"
#include "TC654.h"
#include "IGetFanInfo.h"
#include "CommunicationException.h"
#include "Exceptions.h"
#include "PassFailCleanup.h"
#include "TC654Exception.h"
// default constructor
TC654::Status::Status(char value):value(value){

}
bool TC654::Status::GetF1F(){
	return ((value&0x01))>0;
}
bool TC654::Status::GetF2F(){
	return ((value&0x02)>>1)>0;
}
bool TC654::Status::GetR1CO(){
	return ((value&0x08)>>3)>0;
}
bool TC654::Status::GetR2CO(){
return ((value&0x10)>>4)>0;}
TC654::Fan::Fan(TC654* tc654, CallbackGetRPM callbackGetRRPM, CallbackCheck callbackCheck, char* name):name(name), callbackGetRPM(callbackGetRPM), callbackCheck(callbackCheck), tc654(tc654){}


const char* TC654::Fan::GetName(){
	return name;
}
uint16_t TC654::Fan::GetFanSpeed(bool& successful){
	return
	(tc654->*(callbackGetRPM))(successful)*50;
}
PassFailCleanup<Exceptions*> TC654::Fan::Check(){
	return
	(tc654->*(callbackCheck))(name);
}


unsigned char TC654::GetRPM1(bool& successful){
	return ReadRegister(successful, RPM1_ADDRESS);
}
unsigned char TC654::GetRPM2(bool& successful){
	return ReadRegister(successful, RPM2_ADDRESS);
}
PassFailCleanup<Exceptions*> TC654::CheckFan1(const char* name){
	bool successful=true;
	Status status = GetStatus(successful);
	if(!successful)
	{
		Exceptions* exceptions = new Exceptions();
		exceptions->Add(new CommunicationException(name));
		return PassFailCleanup<Exceptions*>(exceptions);
	}
	if(status.GetF1F()||status.GetR1CO())
	{
		Exceptions* exceptions = new Exceptions();
		if(status.GetF1F())
		exceptions->Add(new TC654Exception(name, TC654Exception::Fault));
		if(status.GetR1CO())
		exceptions->Add(new TC654Exception(name, TC654Exception::CounterOverflow));
		return PassFailCleanup<Exceptions*>(exceptions);

	}
	return PassFailCleanup<Exceptions*>();
}
PassFailCleanup<Exceptions*> TC654::CheckFan2(const char* name){
	bool successful=true;
	Status status = GetStatus(successful);
	if(!successful)
	{
		Exceptions* exceptions = new Exceptions();
		exceptions->Add(new CommunicationException(name));
		return PassFailCleanup<Exceptions*>(exceptions);
	}
	if(status.GetF2F()||status.GetR2CO())
	{
		Exceptions* exceptions = new Exceptions();
		if(status.GetF2F())
		exceptions->Add(new TC654Exception(name, TC654Exception::Fault));
		if(status.GetR2CO())
		exceptions->Add(new TC654Exception(name, TC654Exception::CounterOverflow));
		return PassFailCleanup<Exceptions*>(exceptions);

	}
	return PassFailCleanup<Exceptions*>();
}
TC654::TC654(char F1PPR, char F2PPR):fan1(Fan(this, &TC654::GetRPM1,&TC654::CheckFan1, "tc654_1")), fan2(Fan(this, &TC654::GetRPM2, &TC654::CheckFan2, "tc654_2"))
{
	this->F1PPR=(0x0f&F1PPR)<<2;
	this->F2PPR=(0x0f&F2PPR)<<6;
} //TC654
void TC654::WriteConfigurationRegister(bool& successful, char configuration){
	WriteRegister(successful, CONFIG_ADDRESS, configuration);
}

void TC654::WriteRegister(bool& successful, char address, char value){
	i2c_start_wait(ADDRESS_WRITE);
	char r=i2c_write(address);
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
unsigned char TC654::ReadConfigurationRegister(bool& successful){
	return ReadRegister(successful, CONFIG_ADDRESS);
}
unsigned char TC654::ReadRegister(bool& successful, char address){
	i2c_start_wait(ADDRESS_WRITE);
	char r=i2c_write(address);
	if(r!=0){
		successful=false;
		i2c_stop();
		return 0;
	}
	r=i2c_rep_start(ADDRESS_READ);
	if(r!=0){
		successful=false;
		i2c_stop();
		return 0;
	}
	r = i2c_readNak();
	i2c_stop();
	return r;
}
void TC654::Configure(bool& successful){
	char configuration = 0x20|F1PPR|F2PPR;
	WriteConfigurationRegister(successful, configuration);
	if(successful)
	{
		char r = ReadConfigurationRegister(successful);
		if(successful)
		if(r!=configuration)successful = false;
	}
}
unsigned char TC654::GetFanFault1(bool& successful){
	return ReadRegister(successful, FAN_FAULT1_ADDRESS);
}
unsigned char TC654::GetFanFault2(bool& successful){
	return ReadRegister(successful, FAN_FAULT2_ADDRESS);
}
void TC654::SetFanFault2(bool& successful, unsigned char value){
	WriteRegister(successful, FAN_FAULT2_ADDRESS, value);
}
void TC654::SetFanFault1(bool& successful, unsigned char value){
	WriteRegister(successful, FAN_FAULT1_ADDRESS, value);
}
unsigned char TC654::GetDutyCycle(bool& successful){
	return ReadRegister(successful, DUTY_CYCLE_ADDRESS);
}
void TC654::SetDutyCycle(bool& successful, unsigned char value){
	WriteRegister(successful, DUTY_CYCLE_ADDRESS, value);
}
TC654::Status TC654::GetStatus(bool& successful){
	return Status(ReadRegister(successful, STATUS_ADDRESS));
}
IGetFanInfo* TC654::GetIGetFan1Info(){
	return &fan1;
}
IGetFanInfo* TC654::GetIGetFan2Info(){
	return &fan2;
}

// default destructor
TC654::~TC654()
{
} //~LM75
