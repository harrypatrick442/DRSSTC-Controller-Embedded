/*
* RGBC.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __RGBC_H__
#define __RGBC_H__
 #include <stdint.h>
 #include "Cleanup.h"
class RGBC
{
	public:
	const uint16_t r;
	const uint16_t g;
	const uint16_t b;
	const uint16_t c;
	RGBC(uint16_t r, uint16_t g, uint16_t b, uint16_t c):r(r), g(g), b(b), c(c){

	}
	RGBC():r(0), g(0), b(0), c(0){
		
	}
	Cleanup<char*> ToString();
	protected:
	private:
};

#endif
