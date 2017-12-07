/*
* Outputs.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include "PassFailCleanup.h"

// failure constructor

template <class T> PassFailCleanup<T>::PassFailCleanup(T payload):payload(payload), successful(false)
{
}
//successful constructor

template <class T> PassFailCleanup<T>::PassFailCleanup():successful(true)
{
}

// default destructor

template <class T>PassFailCleanup<T>::~PassFailCleanup()
{
if(!successful)
delete payload;
} //~Fans