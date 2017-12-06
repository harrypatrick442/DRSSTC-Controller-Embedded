/*
* PassFailCleanup.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __PASSFAILCLEANUP_H__
#define __PASSFAILCLEANUP_H__
#include "Exceptions.h"

class PassFailCleanup//cleans up mallocated exceptions once it goes out of scope
{
	//variables
	public:
	const bool successful;
	const Exceptions* exceptions;
	protected:
	private:
	//functions
	public:PassFailCleanup(Exceptions* exceptions);
	//successful constructor
	PassFailCleanup();
	// default destructor
	~PassFailCleanup();
	protected:
	private:
}; //Outputs

#endif __PASSFAILCLEANUP_H__



