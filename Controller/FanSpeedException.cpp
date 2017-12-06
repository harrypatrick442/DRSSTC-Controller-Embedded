/*
* Outputs.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/

#include <avr/io.h>
#include "FanSpeedException.h"

// default constructor
FanSpeedException::FanSpeedException(const char* name, uint16_t actualSpeed, uint16_t minSpeedRequired)
{
} //Outputs

// default destructor
FanSpeedException::~FanSpeedException()
{
} //~Fans