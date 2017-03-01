/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/1/2017

	This class represents a Transction object. Each object stores information about the Transaction
	type and Customer ID associated with the Transaction. This class has the functionality to take
	in a data stream with the method setData() in order to populate its data members.
	The method displayTransaction() will neatly print a Transaction object's information to the
	console.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef transaction_h
#define transaction_h

using namespace std;

class Transaction {

	public:
	
	virtual Transaction(void);							//deafult no-args constructor
	virtual Transaction(const Transaction& tocopy);		//copy constructor
	virtual ~Transaction(void);							//destructor
	
	/*------------------------------------------------------------------------------------------------

		Method takes in a file stream and a char indicating the type of Transaction. Method populates
		a Transaction object's data members by calling setters as helper methods for error checking.
		If any of the setters returns false then setData() will return false and the object should
		be deleted.

	------------------------------------------------------------------------------------------------*/


	virtual setData(ifstream& inFile, char type);
	
	/*------------------------------------------------------------------------------------------------

		Method neatly prints all of a Transaction object's information to the console.

		NOTES:	Method cannot change any data members.

	------------------------------------------------------------------------------------------------*/

	virtual displayTransaction(void) const;	

	//getters
	int getCustomerID(void) const;
	char getTransationType(void) const;

	/*------------------------------------------------------------------------------------------------

		Setter method for customerID. Returns a bool indicating success.

		PRECONDITIONS:
			- input must be greater than 999
			- input must be less than 10000

		POSTCONDITIONS:
			- sets customerID to input

	------------------------------------------------------------------------------------------------*/

	bool setCustomerID(int input);

	/*------------------------------------------------------------------------------------------------

		Setter method for transactionType. Returns a bool indicating success.

		PRECONDITIONS:
			- input cannot be a empty

		POSTCONDITIONS:
			- sets transactionType to input

	------------------------------------------------------------------------------------------------*/

	bool setTransactionType(char input);

	virtual Transaction& operator=(const Transaction& toCopy);

	private:
	
	char transactionType = '';
	int customerID = 0;
};

#endif // !transaction_h