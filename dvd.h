/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/13/2017

	This class represents a DVD object. Each object stores information about the title, director,
	release year, and number of copies in inventory. Getter and setter methods are available
	for all data members. This class has the functionality to take in a data stream with the
	method setData() in order to populate its data members. Overloaded comparison operators
	allow for comparing DVD objects, and the method adjustInventory() can be called to increase
	or decrease the inventory amount. The method display() will neatly print a DVD object's
	information to the console.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef dvd_h
#define dvd_h

#include <string>
#include <iostream>
#include "Media.h"

using namespace std;

class DVD : public Media
{

public:

	DVD(void);
	virtual ~DVD(void);
	DVD(const DVD& toCopy);

	virtual bool setData(istream& inFile);
	virtual void display(void) const;

	char getType(void) const;
	string getTitle(void) const;
	string getDirector(void) const;
	int getYear(void) const;

	bool setType(char input);
	bool setTitle(string input);
	bool setDirector(string input);
	bool setYear(int input);

	virtual DVD& operator=(const DVD& toCopy);
	virtual bool operator==(const DVD& toCompare) const;
	virtual bool operator!=(const DVD& toCompare) const;

protected:

	char type = ' ';
	string title = "";
	string director = "";

};

#endif