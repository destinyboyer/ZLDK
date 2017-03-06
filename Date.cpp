#include "stdafx.h"
#include "Date.h"



////////////////////////////////////////////////////////////////////////////////
//																			  //
//							Constructors / Destructors						  //
//																			  //
////////////////////////////////////////////////////////////////////////////////



Date::Date()
{
}


Date::~Date()
{
}



////////////////////////////////////////////////////////////////////////////////
//																			  //
//								Public Methods								  //
//																			  //
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
//								Getters / Setters							  //
////////////////////////////////////////////////////////////////////////////////



int Date::getDay(void) const
{
	return this->day;
}

int Date::getMonth(void) const
{
	return this->month;
}

int Date::getYear(void) const
{
	return this->year;
}

bool Date::setDay(int input)
{
	this->day = input;
	return true;
}

bool Date::setMonth(int input)
{
	this->month = input;
	return true;
}

bool Date::setYear(int input)
{
	this->year = input;
	return true;
}



////////////////////////////////////////////////////////////////////////////////
//									Operators								  //
////////////////////////////////////////////////////////////////////////////////



bool Date::operator==(const Date & toCompare) const
{
	return (this->getDay() == toCompare.getDay() &&
		this->getMonth() == toCompare.getMonth() &&
		this->getYear() == toCompare.getYear());
}

bool Date::operator!=(const Date & toCompare) const
{
	return !(*this == toCompare);
}

bool Date::operator<(const Date & toCompare) const
{
	 return ((this->getYear() * 10000 + this->getMonth() * 100 + this->getDay())
	 < (toCompare.getYear()*10000 + toCompare.getMonth()*100 + this->getDay()));
}

bool Date::operator>(const Date & toCompare) const
{
	return ( !(*this < toCompare) && (*this != toCompare) );
}
