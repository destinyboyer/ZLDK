/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/13/2017

	DVD child class to represent DVD's of type Classic. Classic DVD objects are a special
	case and require uniquely overloaded comparison operators for insertion into the
	inventory management data structure and for populating data members.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef classic_h
#define classic_h

#include "DVD.h"

using namespace std;

class Classic : public DVD
{

public:

	Classic(void);				//good
	Classic(const Classic& toCopy);
	~Classic(void);				//good

	bool setData(istream& inFile);
	void display(void);

	string getActor(void) const;
	int getMonth(void) const;

	bool setActor(string input);
	bool setMonth(int input);

	Classic& operator=(const Classic& toCopy);

private:

	string majorActor = "";
	Classic* nextIdentical = nullptr;

};

#endif