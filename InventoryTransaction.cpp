
#include "InventoryTransaction.h"



//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//								Constructors / Destructors										//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////



InventoryTransaction::InventoryTransaction()
{
}

InventoryTransaction::InventoryTransaction(InventoryTransaction & toCopy)
{
	// We can safely use the operator=()
	*this = toCopy;
}


InventoryTransaction::~InventoryTransaction()
{
}



//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//										Public Methods											//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////



bool InventoryTransaction::setData(istream & inFile, char type)
{
	int tempInt;
	char tempChar;
	string tempString;
	bool idSuccess, mediaTypeSuccess, genreSuccess, monthSuccess, yearSuccess, firstNameSuccess, 
		lastNameSuccess, titleSuccess, directorSuccess;
	bool success = false;	// success determines the boolean of all combined successes

	// Type is safe at this point - no further checking required
	this->setTransactionType(type);

	inFile >> tempInt;
	idSuccess = this->setCustomerID(tempInt);

	inFile >> tempChar;
	mediaTypeSuccess = this->setMediaType(tempChar);

	inFile >> tempChar;
	genreSuccess = this->setGenre(tempChar);

	if (!(idSuccess && mediaType && genreSuccess))
	{
		return false;
	}

	switch (this->getGenre())
	{
	case 'F':
		getline(inFile, tempString, ',');
		titleSuccess = this->setTitle(tempString);

		inFile >> tempInt;
		yearSuccess = this->setYear(tempInt);

		success = (titleSuccess && yearSuccess);
		break;
	case 'D':
		getline(inFile, tempString, ',');
		directorSuccess = this->setDirector(tempString);

		getline(inFile, tempString, ',');
		titleSuccess = this->setTitle(tempString);
		
		success = (directorSuccess && titleSuccess);
		break;
	case 'C':
		inFile >> tempInt;
		monthSuccess = this->setMonth(tempInt);

		inFile >> tempInt;
		yearSuccess = this->setYear(tempInt);

		inFile >> tempString;
		firstNameSuccess = this->setFirstName(tempString);

		inFile >> tempString;
		lastNameSuccess = this->setLastName(tempString);
		
		success = (monthSuccess && yearSuccess && firstNameSuccess && lastNameSuccess);
		break;
	}
	getline(inFile, tempString);

	return success;
}



//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//										Getters / Setters										//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////



void InventoryTransaction::displayTransaction(void) const
{
	cout << this->getTransationType() << " " << this->getCustomerID() << " " <<
		this->getMediaType() << " " << this->getGenre() << " ";
	switch (this->getGenre())
	{
	case 'F':
		cout << this->getTitle() << ", " << this->getYear();
		break;
	case 'D':
		cout << this->getDirector() << ", " << this->getTitle() << ",";
		break;
	case 'C':
		cout << this->getMonth() << " " << this->getYear() << " " << this->getFirstName() << " "
			<< this->getLastName();
	}
	cout << endl;
}

char InventoryTransaction::getMediaType(void) const
{
	return this->mediaType;
}

char InventoryTransaction::getGenre(void) const
{
	return this->genre;
}

string InventoryTransaction::getDirector(void) const
{
	return this->director;
}

string InventoryTransaction::getTitle(void) const
{
	return this->title;
}

string InventoryTransaction::getFirstName(void) const
{
	return this->actorFirstName;
}

string InventoryTransaction::getLastName(void) const
{
	return this->actorLastName;
}

int InventoryTransaction::getYear(void) const
{
	return this->date.getYear();
}

int InventoryTransaction::getMonth(void) const
{
	return this->date.getMonth();
}

int InventoryTransaction::getDay(void) const
{
	return this->date.getDay();
}



bool InventoryTransaction::setMediaType(char input)
{
	if (input != 'D')
	{
		cout << "ERROR: DVD is the only current Media type accepted!" << endl;
		return false;
	}
	this->mediaType = input;
	return true;
}

bool InventoryTransaction::setGenre(char input)
{
	if ((input == 'F') || (input == 'D') || (input == 'C'))
	{
		this->genre = input;
		return true;
	}
	else
	{
		cout << "ERROR: Only Comedy, Drama, and Classic type DVD's allowed!" << endl;
		return false;
	}
}

// We allow our string attributes to be anything, except for an empty string
bool InventoryTransaction::setDirector(string input)
{
	if (input != "")
	{
		this->director = input;
		return true;
	}
	return false;
}

bool InventoryTransaction::setTitle(string input)
{
	if (input != "")
	{
		this->title = input;
		return true;
	}
	return false;
}

bool InventoryTransaction::setLastName(string input)
{
	if (input != "")
	{
		this->actorLastName = input;
		return true;
	}
	return false;
}

bool InventoryTransaction::setFirstName(string input)
{
	if (input != "")
	{
		this->actorFirstName = input;
		return true;
	}
	return false;
}

bool InventoryTransaction::setYear(int input)
{
	return this->date.setYear(input);
}

bool InventoryTransaction::setMonth(int input)
{
	return this->date.setMonth(input);
}

bool InventoryTransaction::setDay(int input)
{
	return this->date.setDay(input);
}



//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//									Overloaded Operators										//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////



InventoryTransaction & InventoryTransaction::operator=(const InventoryTransaction & toCopy)
{
	this->transactionType = toCopy.getTransationType();
	this->customerID = toCopy.getCustomerID();
	this->mediaType = toCopy.getMediaType();
	this->genre = toCopy.getGenre();
	this->director = toCopy.getDirector();
	this->title = toCopy.getTitle();
	this->actorFirstName = toCopy.getFirstName();
	this->actorLastName = toCopy.getLastName();
	this->date = toCopy.date; // Object = Object
	return *this;
}
