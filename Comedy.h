/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/13/2017

	DVD child class to represent DVD's of type Comedy.

-------------------------------------------------------------------------------------------------*/


#pragma once
#ifndef comedy_h
#define comedy_h

#include "DVD.h"

using namespace std;

class Comedy : public DVD
{
public:

	Comedy(void);
	Comedy(const Comedy& toCopy);
	~Comedy(void);
};

#endif