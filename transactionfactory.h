/*-------------------------------------------------------------------------------------------------
	
	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
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
#include "Transaction.h"
#include "InventoryTransaction.h"

class TransactionFactory {

	public:

		/*------------------------------------------------------------------------------------------------

			Method takes in a file stream and a Transaction queue and populates the queue with
			a single Transaction object

		------------------------------------------------------------------------------------------------*/

		static Transaction* createTransaction(istream& inFile, queue<Transaction*>);
};

#endif