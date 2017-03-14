#include "transaction.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//								Constructors / Destructors										//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

Transaction::Transaction(void) {

}

Transaction::Transaction(const Transaction& toCopy) {
	*this = toCopy;
}

Transaction::~Transaction(void) {

}

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//										Public Methods											//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

bool Transaction::setData(istream& inFile, char type)
{	
	int temp;
	bool success = false;

	transactionType = type;

	inFile >> temp;

	success = this->setCustomerID(temp);

	return success;
}

void Transaction::displayTransaction(void) const
{
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//									Getters / Setters											//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

int Transaction::getCustomerID(void) const
{
	return this->customerID;
}

char Transaction::getTransationType(void) const
{
	return this->transactionType;
}

bool Transaction::setCustomerID(int input)
{
	bool success = false;
	
	if (input > 999 && input < 10000)
	{
		customerID = input;
		success = true;
	}

	return success;
}

bool Transaction::setTransactionType(char input) {
	bool success = false;

	if (input == 66 || input == 82 || input == 73 || input == 72) {
		transactionType = input;
		success = true;
	}

	return success;
}