/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		3/1/2017
	Modified:		3/1/2017

	Date class represents a date with data members corresponding to the day, month, and year.
	Class has functionality to take in a data stream in order to populate data members.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef date_h
#define date_h

#include <iostream>

using namespace std;

class Date {

	public:

	Date(void);			//default no-args constructor
	~Date(void);		//destructor

	/*------------------------------------------------------------------------------------------------

		Method takes in a file stream and  populates a Date object's data members by calling setters
		as helper methods for error checking. If any of the setters returns false then setData() will
		return false and the object should be deleted.

	------------------------------------------------------------------------------------------------*/

	bool setData(ifstream& inFile);

	//getters
	int getYear(void) const;
	int getDay(void) const;
	int getMonth(void) const;

	/*------------------------------------------------------------------------------------------------

		Setter method for year. Returns a bool indicating success.

		PRECONDITIONS:
			- input must be greater than 999
			- input must be less that 10000

		POSTCONDITIONS:
			- sets year to input

	------------------------------------------------------------------------------------------------*/

	bool setYear(int input);

	/*------------------------------------------------------------------------------------------------

		Setter method for year. Returns a bool indicating success.

		PRECONDITIONS:
			- input must be greater than 0
			- input must be less that 13

		POSTCONDITIONS:
			- sets month to input

	------------------------------------------------------------------------------------------------*/

	bool setMonth(string input);

	/*------------------------------------------------------------------------------------------------

		Setter method for day. Returns a bool indicating success.

		PRECONDITIONS:
			- input must be greater than 0
			- input must be less that 32

		POSTCONDITIONS:
			- sets day to input

	------------------------------------------------------------------------------------------------*/

	bool setDay(int input);

	Date& operator=(const Date& toCopy);

	private:

	int year = 0;
	int day = 0;
	int month = 0;

};

#endif // !date_h
