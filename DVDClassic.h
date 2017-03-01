/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/1/2017

	DVD child class to represent DVD's of type Classic. Classic DVD objects are a special
	case and require uniquely overloaded comparison operators for insertion into the 
	inventory management data structure and for populating data members.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef classic_h
#define classic_h

#include "dvd.h"

class Classic : public DVD {
	
	public:

	Classic(void);				//default no-args constructor
	Classic(Classic& toCopy);	//copy constructor
	~Classic(void);				//destructor

	bool setData(ifstream& inFile);
	void display(void) const;
	bool operator==(const DVD& toCompare) const;
	bool operator!=(const DVD& toCompare) const;
	bool operator<(const DVD& toCompare) const;
	bool operator>(const DVD& toCompare) const;
	bool operator=(const DVD& toCopy) const;

	string getActor(void) const;
	int getMonth(void) const;

	/*------------------------------------------------------------------------------------------------

		Setter method for releaseYear. Returns a bool indicating success.

		PRECONDITIONS:
			- input cannot be an empty string

		POSTCONDITIONS:
			- sets actor equal to input

	------------------------------------------------------------------------------------------------*/

	bool setActor(string input);

	/*------------------------------------------------------------------------------------------------

		Setter method for releaseMonth. Returns a bool indicating success.

		PRECONDITIONS:
			- input cannot be an empty string

		POSTCONDITIONS:
			- sets releaseMonth equal to the int interpreation of the month

	------------------------------------------------------------------------------------------------*/

	bool setMonth(string input);

	Classic& operator=(const Classic& toCopy);

	private:

	string majorActor = "";
	int releaseMonth = 0;

};

#endif // !classic_h
