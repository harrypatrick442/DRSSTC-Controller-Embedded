/*
* RGBC.c
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


 #include "RGBC.h"
 #include<avr/pgmspace.h>
 #include<stdio.h>
	Cleanup<char*> RGBC::ToString(){
		const char* pstr = PSTR("{\"type\":\"rgbc\",\"r\":%d,\"g\":%d,\"b\":%d,\"c\":%d}\n");
		int length = snprintf_P(NULL, 0, pstr, r, g, b, c);
		char* buf = (char*)malloc(length+1);
		snprintf_P(buf, length + 1,pstr,r, g, b, c);
		return Cleanup<char*>(buf);
	}