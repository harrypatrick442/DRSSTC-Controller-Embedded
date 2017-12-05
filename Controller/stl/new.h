/*
 * new
 *
 *  Created on: 1 Jan 2011
 *      Author: Andy Brown
 */


/**
 * Global operator new
 */

 #ifndef _Included_New__
 #define _Included_New__
 void *operator new(size_t size_)
 {
	 return malloc(size_);
 }

 
 void* operator new[]( size_t size_ )
 {
	 return malloc(size_);
 }
 void* operator new[]( size_t size_ ,void *ptr_){
	
	return ptr_;
 }
/**
 * Global placement operator new
 */

void* operator new(size_t size_,void *ptr_)
{
	return ptr_;
}


/**
 * Global operator delete
 */
 
 void operator delete(void *ptr_)
 {
	 free(ptr_);
 }
 void operator delete[](void *ptr_)
 {
	 free(ptr_);
 }
#endif