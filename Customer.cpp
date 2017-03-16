#include "Customer.h"



//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//								Constructors / Destructors										//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////


Customer::Customer(void)
{
}


Customer::~Customer(void)
{
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//										Public Methods											//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////



bool Customer::setData(istream & inFile)
{
	bool success = false;
	int tempID = 0;
	string tempFirst = "";
	string tempLast = "";
	inFile >> tempID >> tempFirst >> tempLast;

	if (setID(tempID) == true &&
		setFirstName(tempFirst) == true
		&& setLastName(tempLast) == true)
	{
		success = true;
	}
	this->displayCustomer();
	return success;
}

void Customer::displayHistory(void) 
{
	for (vector<Transaction>::iterator it = history.begin(); it != history.end(); ++it) {
		it->displayTransaction();
	}
}

void Customer::displayCustomer(void) const
{
	cout << "Customer ID: " << this->getID() << " First: " << this->firstName << " Last: " << this->lastName << endl;
}

void Customer::displayHolding(void) 
{
	for (vector<DVD>::iterator it = holding.begin(); it != holding.end(); ++it) {
		it->display();
	}
}


void Customer::addTransaction(const Transaction& toAdd)
{
	this->history.push_back(toAdd);
}

void Customer::borrowMedia(InventoryTransaction& transaction)
{
	DVD toPush;
		toPush.setDirector(transaction.getDirector());
		toPush.setTitle(transaction.getTitle());
		toPush.setType(transaction.getGenre());
		this->holding.push_back(toPush);

	this->addTransaction(transaction);
}

void Customer::returnMedia(InventoryTransaction& transaction)
{
	for (vector<DVD>::iterator it = holding.begin(); it != holding.end(); ++it) {
		if (it->getTitle() == transaction.getTitle() &&
			it->getType() == transaction.getTransationType()) {
			this->holding.erase(it);
			break;
		}
	}
	this->addTransaction(transaction);
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//									Getters / Setters											//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

/*------------------------------------------------------------------------------------------------

	Getter method for ID. Method cannot change any data members.

------------------------------------------------------------------------------------------------*/

int Customer::getID(void) const
{
	return this->ID;
}

/*------------------------------------------------------------------------------------------------

	Getter method for firstName. Method cannot change any data members.

------------------------------------------------------------------------------------------------*/

string Customer::getFistName(void) const
{
	return this->firstName;
}

/*------------------------------------------------------------------------------------------------

	Getter method for lastName. Method cannot change any data members.

------------------------------------------------------------------------------------------------*/

string Customer::getLastName(void) const {
	return this->lastName;
}

/*------------------------------------------------------------------------------------------------

	Setter method for firstName. Sets firstName equal to input. Returns a bool indicating
	success.

	PRECONDITIONS:
		- input cannot be equal to an empty string

	POSTCONDITIONS:
		- sets firstName equal to input

------------------------------------------------------------------------------------------------*/

bool Customer::setFirstName(string input)
{
	bool success = false;

	if (input != "")
	{
		this->firstName = input;
		success = true;
	}

	return success;
}

/*------------------------------------------------------------------------------------------------

	Setter method for lastName. Sets lastName equal to input. Returns a bool indicating
	success.

	PRECONDITIONS:
		- input cannot be equal to an empty string

	POSTCONDITIONS:
		- sets lastName equal to input

------------------------------------------------------------------------------------------------*/

bool Customer::setLastName(string input)
{
	bool success = false;

	if (input != "")
	{
		this->lastName = input;
		success = true;
	}

	return success;
}

/*------------------------------------------------------------------------------------------------

	Setter method for ID. Sets ID equal to input. Returns a bool indicating
	success.

	PRECONDITIONS:
		- input cannot be less than 1000
		- input cannot be greater than 9999

	POSTCONDITIONS:
		- sets ID equal to input

------------------------------------------------------------------------------------------------*/

bool Customer::setID(int input)
{
	bool success = false;

	if (input > 999 && input < 10000)
	{
		this->ID = input;
		success = true;
	}

	return success;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//									Overloaded Operators										//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

//Customer& Customer::operator=(const Customer& toCopy)
//{
//
//}