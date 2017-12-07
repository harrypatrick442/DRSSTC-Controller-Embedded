/*
* PassFailCleanup.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __PASSFAILCLEANUP_H__
#define __PASSFAILCLEANUP_H__

template <class T>    class PassFailCleanup//cleans up mallocated exceptions once it goes out of scope
{
	//variables
	public:
	const bool successful;
	const T payload;
	protected:
	private:
	//functions
	public:PassFailCleanup<T>(T payload);
	//successful constructor
	PassFailCleanup();
	// default destructor
	~PassFailCleanup();
	protected:
	private:
}; //Outputs

#endif __PASSFAILCLEANUP_H__



