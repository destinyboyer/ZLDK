/*-------------------------------------------------------------------------------------------------
	
	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		2/28/2017

	This is a factory class to create transaction objects at runtime based on the type of
	transaction. Different transaction types have different responsibilities in performing
	actions between inventory and customers.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef transactionfactory_h
#define transactionfactory_h

#include <iostream>
#include "transaction.h"

class TransactionFactory {

	public:
		TransactionFactory(void);		//constructor
		~TransactionFactory(void);		//destructor
		static Transaction* createTransaction(ifstream& inFile);		//creates new Transaction objects
};

#endif