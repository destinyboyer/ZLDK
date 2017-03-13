#include "DVD.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//								Constructors / Destructors										//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

DVD::DVD(void)
{
	this->date = new Date();
}

DVD::~DVD(void)
{
}

DVD::DVD(const DVD& toCopy)
{
	this->date = new Date();
	*this = toCopy;
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
		- data must be formatted for DVD objects

------------------------------------------------------------------------------------------------*/

bool DVD::setData(istream & inFile)
{
	bool success = false;
	bool typeSuccess, yearSuccess, directorSuccess, titleSuccess;
	string temp = "";
	int tempNum = 0;
	typeSuccess = this->setType(inFile.get());
	// This line removes all content up until the next comma
	getline(inFile, temp, ',');
	
	inFile >> temp;						//gets inventory number
	
	if (tempNum > -1) {					//sets inventory if temp >= 0
		this->adjustInventory(tempNum);
	}

	getline(inFile, temp, ',');			//fills temp with director's name

	directorSuccess = this->setDirector(temp);

	getline(inFile, temp, ',');			//fills temp wih the title

	titleSuccess = this->setTitle(temp);

	inFile >> tempNum;

	yearSuccess = this->setYear(tempNum);

	if (typeSuccess == true && directorSuccess == true &&
		yearSuccess == true && titleSuccess == true)
	{
		success = true;
	}
	return success;
}

/*------------------------------------------------------------------------------------------------

	Method prints all information of a DVD object to the console in an easy-to-read format.

	NOTES:	Method cannot change any data members.

------------------------------------------------------------------------------------------------*/

void DVD::display(void) const
{
	cout << this->type << ", " << this->inventory << ", " << this->director 
		<< ", " << this->title << ", " << this->date->getYear() << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//									Getters / Setters											//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

/*------------------------------------------------------------------------------------------------

	Getter method for type.

	NOTES:	Method cannot change any data members.

------------------------------------------------------------------------------------------------*/

char DVD::getType(void) const
{
	return this->type;
}

/*------------------------------------------------------------------------------------------------

	Getter method for title.

	NOTES:	Method cannot change any data members.

------------------------------------------------------------------------------------------------*/

string DVD::getTitle(void) const
{
	return this->title;
}

/*------------------------------------------------------------------------------------------------

	Getter method for director.

	NOTES:	Method cannot change any data members.

------------------------------------------------------------------------------------------------*/

string DVD::getDirector(void) const
{
	return this->director;
}

/*------------------------------------------------------------------------------------------------

	Getter method for year.

	NOTES:	Method cannot change any data members.

------------------------------------------------------------------------------------------------*/

int DVD::getYear(void) const
{
	return this->date->getYear();
}

/*------------------------------------------------------------------------------------------------

	Setter method for type. Returns a bool indicating success.

	PRECONDITIONS:
		- input cannot be an empty string

	POSTCONDITIONS:
		- sets type equal to input

------------------------------------------------------------------------------------------------*/

bool DVD::setType(char input)
{
	bool success = false;
	if (input != ' ')
	{
		this->type = input;
		success = true;
	}
	return success;
}

/*------------------------------------------------------------------------------------------------

	Setter method for title. Returns a bool indicating success.

	PRECONDITIONS:
		- input cannot be an empty string

	POSTCONDITIONS:
		- sets title equal to input

------------------------------------------------------------------------------------------------*/

bool DVD::setTitle(string input)
{
	bool success = false;
	if (input != "")
	{
		this->title = input;
		success = true;
	}
	return success;
}
/*------------------------------------------------------------------------------------------------

	Setter method for director. Returns a bool indicating success.

	PRECONDITIONS:
		- input cannot be an empty string

	POSTCONDITIONS:
		- sets director equal to input

------------------------------------------------------------------------------------------------*/

bool DVD::setDirector(string input)
{
	bool success = false;
	if (input != "") {
		this->director = input;
		success = true;
	}
	return success;
}

/*------------------------------------------------------------------------------------------------

	Setter method for year. Returns a bool indicating success. Uses date setter methods as
	helper methods. Returns a bool indicating success.

------------------------------------------------------------------------------------------------*/

bool DVD::setYear(int input)
{
	return this->date->setYear(input);
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

DVD& DVD::operator=(const DVD& toCopy)
{
	if (*this != toCopy)
	{
		delete this->date;
		this->date = new Date();
		this->date->setYear(toCopy.date->getYear());
		this->type = toCopy.getType();
		this->title = toCopy.getTitle();
		this->director = toCopy.getDirector();
		this->inventory = toCopy.getInventory();
	}
	return *this;
}

/*------------------------------------------------------------------------------------------------

	Overloaded equality operator. Returns a bool indicating whether two DVD
	objects are equal comparing all data members.

	POSTCONDITIONS:
		- returns a bool indicating whether two DVD objects are equal

------------------------------------------------------------------------------------------------*/

bool DVD::operator==(const DVD& toCompare) const
{
	return (this->title == toCompare.title &&
		this->director == toCompare.director &&
		this->type == toCompare.type &&
		this->inventory == toCompare.inventory &&
		this->date->getYear() == toCompare.date->getYear());
}

/*------------------------------------------------------------------------------------------------

	Overloaded inequality operator. Returns a bool indicating whether two DVD
	objects are equal comparing all data members. Uses the overloaded equality
	method as a helper.

	POSTCONDITIONS:
		- returns a bool indicating whether two DVD objects are equal

------------------------------------------------------------------------------------------------*/

bool DVD::operator!=(const DVD& toCompare) const
{
	return !(*this == toCompare);
}