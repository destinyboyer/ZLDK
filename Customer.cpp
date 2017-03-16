#include "Customer.h"



//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//								Constructors / Destructors										//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////


Customer::Customer(void)
{
}

Customer::Customer(const Customer& toCopy)
{
	*this = toCopy;
}

Customer::~Customer(void)
{
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//										Public Methods											//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

/*------------------------------------------------------------------------------------------------

	Method takes in a file stream and populates the customer's data members by calling the
	setter methods. Setters are used as hepler methods for error checking. If any setter
	method returns false, then setData will return false and the object should be deleted.

	PRECONDITIONS:
		- data must be formatted for customer objects

------------------------------------------------------------------------------------------------*/

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

/*------------------------------------------------------------------------------------------------

	Method prints the Transaction history associated with a customer.

	NOTES:	Method cannot change any data members.

------------------------------------------------------------------------------------------------*/


void Customer::displayHistory(void) 
{
	for (vector<Transaction>::iterator it = history.begin(); it != history.end(); ++it) {
		it->displayTransaction();
	}
}

/*------------------------------------------------------------------------------------------------

	Method prints information associated with a Customer object to the console.

	NOTES:	Method cannot change any data members.

------------------------------------------------------------------------------------------------*/


void Customer::displayCustomer(void) const
{
	cout << "Customer ID: " << this->getID() << " First: " << this->firstName << " Last: " << this->lastName << endl;
}

/*------------------------------------------------------------------------------------------------

	Method prints the current DVD items that a Customer has checked out.

	NOTES:	Method cannot change any data members.

------------------------------------------------------------------------------------------------*/


void Customer::displayHolding(void) 
{
	for (vector<DVD>::iterator it = holding.begin(); it != holding.end(); ++it) {
		it->display();
	}
}

/*------------------------------------------------------------------------------------------------

	Method takes in a Transaction object and adds it to the history queue.

------------------------------------------------------------------------------------------------*/

void Customer::addTransaction(const Transaction& toAdd)
{
	this->history.push_back(toAdd);
}

/*------------------------------------------------------------------------------------------------

	Method takes in a Transaction object and calls addTransaction() to add the Transaction
	to the Customer's history. The Transaction is also stored in the Customer's holding
	vector indicating that they have checked the item out of the store's inventory.

------------------------------------------------------------------------------------------------*/


void Customer::borrowMedia(InventoryTransaction& transaction)
{
	DVD toPush;
		toPush.setDirector(transaction.getDirector());
		toPush.setTitle(transaction.getTitle());
		toPush.setType(transaction.getGenre());
		this->holding.push_back(toPush);

	this->addTransaction(transaction);
}

/*------------------------------------------------------------------------------------------------

	Method takes in a Transaction object and calls addTransaction() to add the Transaction
	to the Customer's history. The Transaction concerning the same Media item is then found
	in the Customer's holding vector and deleted, indicating that the item has been returned.

------------------------------------------------------------------------------------------------*/


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

Customer& Customer::operator=(const Customer& toCopy)
{
	this->ID = toCopy.ID;
	this->firstName = toCopy.firstName;
	this->lastName = toCopy.lastName;
	this->history = toCopy.history;
	this->holding = toCopy.holding;
	return *this;
}