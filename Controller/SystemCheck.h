/* 
* SystemCheck.h
*
* Created: 22/11/2017 21:50:06
* Author: SoftwareEngineer
*/


#ifndef __SYSTEMCHECK_H__
#define __SYSTEMCHECK_H__

#include "ISystemCheck.h"
#include  "Exceptions.h"	
class SystemCheck:public ISystemCheck
{
	//variables
	public:
	protected:
	private:
	static SystemCheck _Singleton;



	//functions
	public:
	static  SystemCheck& GetInstance();
	void SetInterfaces();
	void Check( bool& successful, Exceptions& exceptions);
	protected:
	private:
	void Initialize ();
	void operator=(SystemCheck const&) = delete; // Don't implement

}; //SystemCheck

#endif //__SYSTEMCHECK_H__
