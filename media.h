/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/13/2017

	High-level parent class for Media types for the store. Increases extensibility.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef media_h
#define media_h

#include "Date.h"
#include <iostream>

using namespace std;

class Media
{
public:

	Media(void);
	virtual ~Media(void);

	virtual bool setData(istream& inFile);
	virtual void display(void) const;

	bool adjustInventory(int input);

	int getInventory(void) const;

	virtual bool operator==(const Media& toCompare) const;
	virtual bool operator!=(const Media& toCompare) const;
	virtual bool operator<(const Media& toCompare) const;
	virtual bool operator>(const Media& toCompare) const;

protected:

	Date* date = nullptr;
	int inventory = 0;
};

#endif