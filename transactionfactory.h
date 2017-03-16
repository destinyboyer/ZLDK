/*-------------------------------------------------------------------------------------------------
	
	Authors:		Boyer, Destiny
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/15/2017

	This is a factory class to create transaction objects at runtime based on the type of
	transaction. Different transaction types have different responsibilities in performing
	actions between inventory and customers.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef transactionfactory_h
#define transactionfactory_h

#include <iostream>
#include <queue>
#include "transaction.h"
#include "inventoryTransaction.h"

class TransactionFactory {

	public:

		/*------------------------------------------------------------------------------------------------

			Method takes in a file stream and a Transaction queue and populates the queue with
			Transaction objects.

		------------------------------------------------------------------------------------------------*/

		static void buildTransactions(istream& inFile, queue<Transaction>*);		//creates new Transaction objects
};

#endif

void TransactionFactory::buildTransactions(istream& inFile, queue<Transaction>* process) {
	char temp = ' ';
	bool successfulRead = false;
	bool success = false;
	Transaction* ptr;

	inFile >> temp;

	while (true) {
		if (temp == 'B' || temp == 'R') {

			ptr = new InventoryTransaction();

		} else if (temp == 'H') {
			ptr = new Transaction();
		}

		successfulRead = ptr->setData(inFile, temp);

		if (inFile.eof()) {
			delete ptr;
			break;
		}

		if (successfulRead) {
			process->push(*ptr);
		} else {
			delete ptr;
		}
	}
}