#pragma once
#ifndef media_h
#define media_h

#include "Date.h"

using namespace std;

class Media
{
public:
	Media(void);
	virtual ~Media(void);

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