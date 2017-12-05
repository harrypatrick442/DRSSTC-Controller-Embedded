/* 
* SystemCheck.h
*
* Created: 22/11/2017 21:50:06
* Author: SoftwareEngineer
*/


#ifndef __SYSTEMCHECK_H__
#define __SYSTEMCHECK_H__


class SystemCheck
{
	//variables
	public:
	protected:
	private:
	static SystemCheck _Singleton;

	//functions
	public:
	static  SystemCheck& GetInstance();
	protected:
	private:
	void Initialize ();
	void operator=(SystemCheck const&) = delete; // Don't implement

}; //SystemCheck

#endif //__SYSTEMCHECK_H__
