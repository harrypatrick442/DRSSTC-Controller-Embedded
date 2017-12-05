/* 
* IGETFANSPEED.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __IGETFANSPEED_H__
#define __IGETFANSPEED_H__
class IGetFanSpeed{ 
public: virtual uint16_t GetFanSpeed(bool& successful)=0;
};
#endif //__IGETFANSPEED_H__
