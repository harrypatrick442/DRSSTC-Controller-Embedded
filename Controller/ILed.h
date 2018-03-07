/* 
* ISendMessage.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __ILED_H__
#define __ILED_H__
class ILed {
	public:
	virtual void TurnOn() = 0;
	virtual void TurnOff()=0;
};
#endif //__ISENDMESSAGE_H__
