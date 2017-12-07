/*
* Exceptions.cpp
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#include "Exceptions.h"
#include <stdlib.h>
// default constructor
Exceptions::Exceptions(){

} //Outputs
void Exceptions::Consume(Exceptions* exceptions)
{
	unsigned int size = exceptions->exceptions.size();
	for(unsigned int i = 0; i<size; i++){
		Exception * exception = exceptions->exceptions[i];
		if(exception!=NULL)
		this->exceptions.push_back(exception);
		exceptions->exceptions[i]=NULL;
	}
	delete exceptions;
}
void Exceptions::Add(Exception* exception){
exceptions.push_back(exception);}
unsigned int Exceptions::Count(){
	return exceptions.size();
}
// default destructor
Exceptions::~Exceptions()
{
	unsigned int size = exceptions.size();
	for(unsigned int i=0; i<size; i++){
		if(exceptions[i]!=NULL)
		delete exceptions[i];
	}
} //~Exceptions

