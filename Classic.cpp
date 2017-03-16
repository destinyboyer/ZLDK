
#include "Classic.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//								Constructors / Destructors										//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

Classic::Classic(void)
{
}

Classic::Classic(const Classic& toCopy)
{
	*this = toCopy;
}

Classic::~Classic(void)
{
	nextIdentical = nullptr;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//										Public Methods											//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

/*------------------------------------------------------------------------------------------------

	Method takes in a file stream and populates the DVD's data members by calling the
	setter methods. Setters are used as hepler methods for error checking. If any setter
	method returns false, then setData will return false and the object should be deleted.

	PRECONDITIONS:
		- data must be formatted for Classic objects

------------------------------------------------------------------------------------------------*/

bool Classic::setData(istream & inFile)
{
	bool success = false;
	bool directorSuccess, actorSuccess, titleSuccess, monthSuccess, yearSuccess;
	string temp, first, last;
	int tempNum;
	this->setType(inFile.get());
	// This line removes all content up until the next comma
	getline(inFile, temp, ',');
	
	inFile >> tempNum;

	if (tempNum > -1) {
		this->adjustInventory(tempNum);
	}

	getline(inFile, temp, ',');
	getline(inFile, temp, ',');

	directorSuccess = this->setDirector(temp);

	getline(inFile, temp, ',');

	titleSuccess = this->setTitle(temp);

	inFile >> first >> last;

	actorSuccess = this->setActor(first + " " + last);
	
	inFile >> tempNum;
	monthSuccess = this->setMonth(tempNum);
	
	inFile >> tempNum;
	yearSuccess = this->setYear(tempNum);
	
	// Do error checking to decide return
	getline(inFile, temp);

	if (directorSuccess == true && actorSuccess == true && titleSuccess == true
		&& monthSuccess == true && yearSuccess == true) {
		success = true;
	}

	return success;
}

void Classic::display(void)
{
	cout << this->type << ", " << this->inventory << ", " << this->director
		<< ", " << this->title << ", " << this->majorActor << " "
		<< this->date->getMonth() << " " << this->date->getYear() << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//									Getters / Setters											//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

/*------------------------------------------------------------------------------------------------

	Getter method for majorActor.

------------------------------------------------------------------------------------------------*/

string Classic::getActor(void) const
{
	return this->majorActor;
}

/*------------------------------------------------------------------------------------------------

	Getter method for month.

------------------------------------------------------------------------------------------------*/

int Classic::getMonth(void) const
{
	return this->date->getMonth();
}

/*------------------------------------------------------------------------------------------------

	Setter method for majorActor. Returns a bool indicating success.

	PRECONDITIONS:
		- input cannot be an empty string

	POSTCONDITIONS:
		- sets actor equal to input

------------------------------------------------------------------------------------------------*/

bool Classic::setActor(string input)
{
	bool success = false;
	if (input != "") {
		this->majorActor = input;
		success = true;
	}
	return success;
}

/*------------------------------------------------------------------------------------------------

	Setter method for releaseYear. Returns a bool indicating success. Uses the date
	setter methods as helpers.

	POSTCONDITIONS:
		- sets month equal to input

------------------------------------------------------------------------------------------------*/

bool Classic::setMonth(int input)
{
	return this->date->setMonth(input);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//									Overloaded Operators										//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

/*------------------------------------------------------------------------------------------------

	Overloaded assignment operator. Creates a deep copy of the parameter Object.

	PRECONDITIONS:
		- parameter cannot be equal to calling object

	POSTCONDITIONS:
		- makes deep copy of parameter

------------------------------------------------------------------------------------------------*/

Classic& Classic::operator=(const Classic& toCopy)
{
	if (*this != toCopy) {
		delete this->date;
		this->date = new Date(*toCopy.date);
		this->type = toCopy.getType();
		this->title = toCopy.getTitle();
		this->director = toCopy.getDirector();
		this->inventory = toCopy.getInventory();
		this->majorActor = toCopy.majorActor;
	}
	return *this;
}