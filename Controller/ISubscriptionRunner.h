/*
* ICheck.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __ISUBSCRIPTIONRUNNER_H__
#define __ISUBSCRIPTIONRUNNER_H__
#include "ISubscriptionRunnable.h"
class ISubscriptionRunner{
	public:virtual void Subscribe(ISubscriptionRunnable* iSubscriptionRunnable)=0;
	virtual void Unsubscribe(ISubscriptionRunnable* iSubscriptionRunnable)=0;
};
#endif //__ISUBSCRIPTIONRUNNER_H__
