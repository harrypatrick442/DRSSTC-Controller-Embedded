/*
* Cleanup.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __Cleanup_H__
#define __Cleanup_H__
#include <stdlib.h>
template <class T>   class Cleanup//cleans up items exceptions once it goes out of scope
{
	//variables
	public:
	const T payload;
	bool dontDelete;
	protected:
	private:
	//functions
	public:
	Cleanup(T payload):payload(payload), dontDelete(false)
	{
	}
	//successful constructor
	Cleanup():payload(NULL), dontDelete(false)
	{
	}

	// default destructor

	~Cleanup()
	{
		if(!dontDelete)
		if(payload!=NULL)
		delete payload;
	}
	void DontDelete(){
		dontDelete=true;
}
Cleanup & operator=(const Cleanup&) = delete;
	//Cleanup(const Cleanup& that) = delete;
	protected:
	private:
}; //Outputs

#endif __Cleanup_H__



