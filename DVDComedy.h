/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/1/2017

	DVD child class to represent DVD's of type Comedy.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef comedy_h
#define comedy_h

#include "dvd.h"

class Comedy : public DVD {

	public:

	Comedy(void);				//default no-args constructor
	Comedy(Comedy& toCopy);		//copy constructor
	~Comedy(void);				//destructor

};

#endif // !comedy_h
