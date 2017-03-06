#include "stdafx.h"
#include "Classic.h"



////////////////////////////////////////////////////////////////////////////////
//																			  //
//							Constructors / Destructors						  //
//																			  //
////////////////////////////////////////////////////////////////////////////////



Classic::Classic()
{
}


Classic::~Classic()
{
}



////////////////////////////////////////////////////////////////////////////////
//																			  //
//								Public Methods								  //
//																			  //
////////////////////////////////////////////////////////////////////////////////



bool Classic::setData(istream & inFile)
{
	string temp, first, last;
	int month, year;
	this->setType(inFile.get());
	// This line removes all content up until the next comma
	getline(inFile, temp, ',');
	inFile >> this->inventory;
	getline(inFile, temp, ',');
	getline(inFile, this->director, ',');
	getline(inFile, this->title, ',');
	inFile >> first;
	inFile >> last;
	this->setActor(first + " " + last);
	inFile >> month;
	this->setMonth(month);
	inFile >> year;
	this->setYear(year);
	// Do error checking to decide return
	this->display();
	return true;
}

void Classic::display(void)
{
	cout << this->type << ", " << this->inventory << ", " << this->director
		<< ", " << this->title << ", " << this->majorActor << " "
		<< this->date->getMonth() << " " << this->date->getYear() << endl;
}



////////////////////////////////////////////////////////////////////////////////
//								Getters / Setters							  //
////////////////////////////////////////////////////////////////////////////////



string Classic::getActor(void) const
{
	return this->majorActor;
}

int Classic::getMonth(void) const
{
	return this->date->getMonth();
}

bool Classic::setActor(string input)
{
	this->majorActor = input;
	return true;
}

bool Classic::setMonth(int input)
{
	return this->date->setMonth(input);
}
