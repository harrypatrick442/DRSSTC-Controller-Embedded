/*
* PassFailCleanup.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __PASSFAILCLEANUP_H__
#define __PASSFAILCLEANUP_H__
#include <stdlib.h>
template <class T>   class PassFailCleanup//cleans up mallocated exceptions once it goes out of scope
{
	//variables
	public:
	const bool successful;
	const T payload;
	protected:
	private:
	//functions
	public:
	PassFailCleanup(T payload):payload(payload), successful(false)
	{
	}
	//successful constructor
PassFailCleanup():successful(true), payload(NULL)
	{
	}

	// default destructor

	~PassFailCleanup()
	{
		if(!successful)
		delete payload;
	} //~Fans
	protected:
	private:
}; //Outputs

#endif __PASSFAILCLEANUP_H__



