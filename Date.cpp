#include "stdafx.h"
#include "Date.h"



//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//								Constructors / Destructors										//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////



Date::Date(void)
{
}

Date::Date(const Date& toCopy)
{
	*this = toCopy;
}

Date::~Date(void)
{
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//										Public Methods											//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

/*------------------------------------------------------------------------------------------------

	Method takes in a file stream and  populates a Date object's data members by calling setters
	as helper methods for error checking. If any of the setters returns false then setData() will
	return false and the object should be deleted.

------------------------------------------------------------------------------------------------*/

bool Date::setData(istream& inFile)
{
	bool success = false;
	bool daySuccess, monthSuccess, yearSuccess;

	int tempDay = 0;
	int tempMonth = 0;
	int tempYear = 0;

	inFile >> tempDay;

	if (tempDay != 0)
	{
		inFile >> tempMonth >> tempYear;
		daySuccess = this->setDay(tempDay);
		monthSuccess = this->setMonth(tempMonth);
		yearSuccess = this->setYear(tempYear);

		if (daySuccess == true && monthSuccess == true
			&& yearSuccess == true)
		{
			success == true;
		}
	}
	return success;
}

/*------------------------------------------------------------------------------------------------

	Method displays the date in month, date, year, format.

	POSTCONDITIONS:
	 - returns a string displaying the date in month, date, year format.

------------------------------------------------------------------------------------------------*/

string Date::display(void) const
{
	string retVal = "";

	stringstream convert;

	convert << getMonth() << "/" << getDay() << "/" << getYear();
	retVal = convert.str();

	return retVal;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//									Getters / Setters											//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

/*------------------------------------------------------------------------------------------------

	Getter method for the day.

	POSTCONDITIONS:
		- returns the day

------------------------------------------------------------------------------------------------*/

int Date::getDay(void) const
{
	return this->day;
}

/*------------------------------------------------------------------------------------------------

	Getter method for the month.

	POSTCONDITIONS:
		- returns the month

------------------------------------------------------------------------------------------------*/

int Date::getMonth(void) const
{
	return this->month;
}

/*------------------------------------------------------------------------------------------------

	Getter method for the year.

	POSTCONDITIONS:
		- returns the year

------------------------------------------------------------------------------------------------*/

int Date::getYear(void) const
{
	return this->year;
}

/*------------------------------------------------------------------------------------------------

	Setter method for day. Returns a bool indicating success.

	PRECONDITIONS:
		- input must be greater than 0
		- input must be less that 32

	POSTCONDITIONS:
		- sets day to input

------------------------------------------------------------------------------------------------*/

bool Date::setDay(int input)
{
	bool success = false;

	if (input > 0 && input < 32)	//checks to ensure that the date
	{								//is in between 1 and 31 (inclusive)
		this->day = input;
		success = true;
	}

	return success;
}

/*------------------------------------------------------------------------------------------------

	Setter method for month. Returns a bool indicating success.

	PRECONDITIONS:
		- input must be greater than 0
		- input must be less that 13

	POSTCONDITIONS:
		- sets month to input

------------------------------------------------------------------------------------------------*/

bool Date::setMonth(int input)
{
	bool success = false;

	if (input > 0 && input < 13)	//checks to ensure that the month
	{								//is in between 1 and 12 (inclusive)
		this->month = input;
		success = true;
	}

	return success;
}

/*------------------------------------------------------------------------------------------------

	Setter method for year. Returns a bool indicating success.

	PRECONDITIONS:
		- input must be greater than 999
		- input must be less that 10000

	POSTCONDITIONS:
		- sets year to input

------------------------------------------------------------------------------------------------*/ 

bool Date::setYear(int input)
{
	bool success = false;

	if (input > 999 && input < 10000)	//checks to ensure that the year
	{									//is a 4 digit number
		this->year = input;
		success = true;
	}

	return success;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//									Overloaded Operators										//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

/*------------------------------------------------------------------------------------------------

	Creates deep copy of a date object.

	POSTCONDITIONS:
	- creates deep copy of a Date object

------------------------------------------------------------------------------------------------*/

Date& Date::operator=(const Date& toCopy)
{
	this->day = toCopy.getDay();
	this->month = toCopy.getMonth();
	this->year = toCopy.getYear();

	return *this;
}

/*------------------------------------------------------------------------------------------------

	Overloaded equality operator. Returns if the month, date, and year of two Date
	objects are equal.

------------------------------------------------------------------------------------------------*/

bool Date::operator==(const Date & toCompare) const
{
	return (this->getDay() == toCompare.getDay() &&
		this->getMonth() == toCompare.getMonth() &&
		this->getYear() == toCompare.getYear());
}

/*------------------------------------------------------------------------------------------------

	Overloaded equality operator. Returns if the month, date, and year of two Date
	objects are not equal. Uses the overloaded equality operator as a helper.

------------------------------------------------------------------------------------------------*/

bool Date::operator!=(const Date & toCompare) const
{
	return !(*this == toCompare);
}
/*------------------------------------------------------------------------------------------------

	Overloaded equality operator. Returns true if the calling object comes before the parameter
	object.

------------------------------------------------------------------------------------------------*/

bool Date::operator<(const Date & toCompare) const
{
	 return ((this->getYear() * 10000 + this->getMonth() * 100 + this->getDay())
	 < (toCompare.getYear() * 10000 + toCompare.getMonth() * 100 + this->getDay()));
}

/*------------------------------------------------------------------------------------------------

	Overloaded equality operator. Returns true if the calling object comes after the parameter
	object.

------------------------------------------------------------------------------------------------*/

bool Date::operator>(const Date & toCompare) const
{
	return ( !(*this < toCompare) && (*this != toCompare) );
}
