/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Selin, Zach

	Created:		3/1/2017
	Modified:		3/13/2017

	Date class represents a date with data members corresponding to the day, month, and year.
	Class has functionality to take in a data stream in order to populate data members.

-------------------------------------------------------------------------------------------------*/


#pragma once
#ifndef date_h
#define date_h

#include <istream>
#include <sstream>
#include <string>

using namespace std;

class Date
{

public:

	Date(void);
	~Date(void);

	bool setData(istream& inFile);

	int getDay(void) const;
	int getMonth(void) const;
	int getYear(void) const;
	
	bool setDay(int input);
	bool setMonth(int input);
	bool setYear(int input);

	string display(void) const;

	Date& operator=(const Date& toCopy);
	bool operator==(const Date& toCompare) const;
	bool operator!=(const Date& toCompare) const;
	bool operator<(const Date& toCompare) const;
	bool operator>(const Date& toCompare) const;

private:

	// default date of 0-0-0000
	int day = 0;
	int month = 0;
	int year = 0000;

};

#endif