/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/1/2017

	DVD child class to represent DVD's of type Drama.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef drama_h
#define drama_h

#include "dvd.h"

class Drama : public DVD {

	public:

	Drama(void);				//default no-args constructor
	Drama(Drama& toCopy);		//copy constructor
	~Drama(void);				//destructor

};

#endif // !drama_h
