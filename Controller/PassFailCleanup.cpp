/*
* Outputs.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include "PassFailCleanup.h"

// failure constructor
PassFailCleanup::PassFailCleanup(Exceptions* exceptions):exceptions(exceptions), successful(false)
{
}
//successful constructor
PassFailCleanup::PassFailCleanup():successful(true)
{
}

// default destructor
PassFailCleanup::~PassFailCleanup()
{
if(!successful)
delete exceptions;
} //~Fans