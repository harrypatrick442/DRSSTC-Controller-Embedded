/*
* Messages.h
*
* Created: 09/10/2017 13:01:34
* Author: SoftwareEngineer
*/


#ifndef __MESSAGES_H__
#define __MESSAGES_H__
#include "Message.h"
#include <stdlib.h>

	class Messages{
		public:
		Message** messages;
		int length;
		Messages(Message* messagesIn[], char lengthIn);
		~Messages();
	};

#endif //__MESSAGES_H__


