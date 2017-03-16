#include "stdafx.h"
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
	string tempString;
	bool success = false;

	this->setTransactionType(type);
	// An 'I' command does not give customer ID, so we just return
	if (this->transactionType == 'I')
	{
		getline(inFile, tempString);	// New line
		return true;
	}

	inFile >> temp;

	getline(inFile, tempString);		// New line

	success = this->setCustomerID(temp);

	return success;
}

void Transaction::displayTransaction(void) const
{
	cout << this->getTransationType();
	if (this->getTransationType() == 'H')
	{
		cout << " " << this->getCustomerID();
	}
	cout << endl;
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