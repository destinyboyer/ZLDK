#pragma once
#ifndef date_h
#define date_h

#include <istream>
#include <string>

using namespace std;

class Date
{
public:
	Date();
	~Date();

	bool setData(istream& inFile);

	int getDay(void) const;
	int getMonth(void) const;
	int getYear(void) const;
	
	bool setDay(int input);
	bool setMonth(int input);
	bool setYear(int input);

	Date& operator=(const Date& toCopy);
	bool operator==(const Date& toCompare) const;
	bool operator!=(const Date& toCompare) const;
	bool operator<(const Date& toCompare) const;
	bool operator>(const Date& toCompare) const;

private:
	// default January 1st, 2000
	int day = 1;
	int month = 1;
	int year = 2000;
};

#endif