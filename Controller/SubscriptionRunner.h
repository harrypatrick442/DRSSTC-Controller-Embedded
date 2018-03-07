/* 
* SubscriptionRunner.h
*
* Created: 17/01/2018 13:21:48
* Author: SoftwareEngineer
*/


#ifndef __SUBSCRIPTIONRUNNER_H__
#define __SUBSCRIPTIONRUNNER_H__
#include "ISubscriptionRunner.h"
#include "ISubscriptionRunnable.h"
#include "simple_vector.h"
class SubscriptionRunner:public ISubscriptionRunner
{
//variables
public:
protected:
private:
simple_vector<ISubscriptionRunnable*> list;
//functions
public:
	SubscriptionRunner();
	~SubscriptionRunner();
	void Subscribe(ISubscriptionRunnable* iSubscriptionRunnable);
	void Unsubscribe(ISubscriptionRunnable* iSubscriptionRunnable);
	void Run();
protected:
private:
	SubscriptionRunner( const SubscriptionRunner &c );
	SubscriptionRunner& operator=( const SubscriptionRunner &c );

}; //SubscriptionRunner

#endif //__SUBSCRIPTIONRUNNER_H__
