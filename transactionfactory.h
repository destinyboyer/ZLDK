/*-------------------------------------------------------------------------------------------------
	
	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/1/2017

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

class TransactionFactory {

	public:

		/*------------------------------------------------------------------------------------------------

			Method takes in a file stream and a Transaction queue and populates the queue with
			Transaction objects.

		------------------------------------------------------------------------------------------------*/

		static Transaction* createTransaction(ifstream& inFile, queue<Transaction>);		//creates new Transaction objects
};

#endif