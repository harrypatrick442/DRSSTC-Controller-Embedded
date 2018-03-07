/* 
* SubscriptionRunner.cpp
*
* Created: 17/01/2018 13:21:48
* Author: SoftwareEngineer
*/


#include "SubscriptionRunner.h"

// default constructor
SubscriptionRunner::SubscriptionRunner()
{
} //SubscriptionRunner

// default destructor
SubscriptionRunner::~SubscriptionRunner()
{
} //~SubscriptionRunner

void SubscriptionRunner::Subscribe(ISubscriptionRunnable* iSubscriptionRunnable)
{
	if(!list.contains(iSubscriptionRunnable))
	{
		list.push_back(iSubscriptionRunnable);
	}
}
void SubscriptionRunner::Unsubscribe(ISubscriptionRunnable* iSubscriptionRunnable)
{
	list.erase(iSubscriptionRunnable);
}
void SubscriptionRunner::Run()
{
	for(int i=0; i<list.size(); i++){list[i]->Run();}
}