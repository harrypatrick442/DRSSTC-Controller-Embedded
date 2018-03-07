/*
* RGBC.c
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


 #include "RGBC.h"
 #include<avr/pgmspace.h>
 #include<stdio.h>
	void RGBC::ToString(char* buf){
		snprintf_P(buf,57,PSTR("{\"type\":\"rgbc\",\"r\":%05d,\"g\":%05d,\"b\":%05d,\"c\":%05d}\n"),r, g, b, c);
	}