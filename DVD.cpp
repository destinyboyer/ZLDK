#include "stdafx.h"
#include "DVD.h"



////////////////////////////////////////////////////////////////////////////////
//																			  //
//							Constructors / Destructors						  //
//																			  //
////////////////////////////////////////////////////////////////////////////////



DVD::DVD()
{
	this->date = new Date;
}


DVD::~DVD()
{
}



////////////////////////////////////////////////////////////////////////////////
//																			  //
//								Public Methods								  //
//																			  //
////////////////////////////////////////////////////////////////////////////////



bool DVD::setData(istream & inFile)
{
	/* Implementation for Transaction - transfer when ready
	// Our default DVD takes in "<title>, <release year>"
	getline(inFile, this->title, ',');
	int year;
	inFile >> year;
	this->date->setYear(year);
	return true;
	*/
	string temp;
	int year;
	this->setType(inFile.get());
	// This line removes all content up until the next comma
	getline(inFile, temp, ',');
	inFile >> this->inventory;
	getline(inFile, temp, ',');
	getline(inFile, this->director, ',');
	getline(inFile, this->title, ',');
	inFile >> year;
	this->setYear(year);
	// Do error checking here to decide return
	this->display();
	return true;
}

void DVD::display(void) const
{
	cout << this->type << ", " << this->inventory << ", " << this->director 
		<< ", " << this->title << ", " << this->date->getYear() << endl;
}



////////////////////////////////////////////////////////////////////////////////
//								Getters / Setters							  //
////////////////////////////////////////////////////////////////////////////////



char DVD::getType(void) const
{
	return this->type;
}

string DVD::getTitle(void) const
{
	return this->title;
}

string DVD::getDirector(void) const
{
	return this->director;
}

int DVD::getYear(void) const
{
	return this->date->getYear();
}

bool DVD::setType(char input)
{
	this->type = input;
	return false;
}

bool DVD::setTitle(string input)
{
	this->title = input;
	return true;
}

bool DVD::setDirector(string input)
{
	this->director = input;
	return true;
}

bool DVD::setYear(int input)
{
	return this->date->setYear(input);
}



////////////////////////////////////////////////////////////////////////////////
//									Operators								  //
////////////////////////////////////////////////////////////////////////////////



bool DVD::operator==(const DVD & toCompare) const
{
	return (this->date == toCompare.date && this->director == toCompare.getDirector() && this->title == toCompare.getTitle());
}

bool DVD::operator!=(const DVD & toCompare) const
{
	return !(*this == toCompare);
}

bool DVD::operator<(const DVD & toCompare) const
{
	return (this->date < toCompare.date);
}

bool DVD::operator>(const DVD & toCompare) const
{
	return (this->date > toCompare.date);
}
