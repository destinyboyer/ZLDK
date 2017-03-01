/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/1/2017

	StoreManager is a Manager class that populates data members and manages the interactions
	between customers and inventory items. Customers are stored in a HashTable, Transactions
	in a queue, and Inventory items in a vector of BinarySearchTree pointers.

	INVARIANTS:
		- Store is set up to handle no more than 10,000 customers

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef storemanager_h
#define storemanager_h

#include <queue>
#include "hashtable.h"
#include "transaction.h"
#include "dvd.h"
#include "customer.h"
#include "binarysearchtree.h"


using namespace std;

class StoreManager {
	
	public:

	StoreManager(void);			//default no-args constructor
	~StoreManager(void);		//default destructor


	/*------------------------------------------------------------------------------------------------

		Method takes in a file stream and passes the file stream to the customers HashTable
		by calling populateTable(). This populates the customer HashTable with customer objects.

		PRECONDITIONS:
			- data must be formatted for Customer objects

		POSTCONDITIONS:
			- populates customers HashTable with customer objects

		NOTES:	Customer objects are solely responsible for knowing how to handle data
				in order to populate data members.

	------------------------------------------------------------------------------------------------*/

	bool setCustomers(ifstream& inFile);

	/*------------------------------------------------------------------------------------------------

		Method takes in a file stream and passes the file stream to the inventory vector. The
		file stream and the inventory vector are then passed to a factory class used to create
		DVD objects and insert them into a BinarySearchTree corresponding to the DVD type.

		PRECONDITIONS:
			- data must be formatted for DVD objects

		POSTCONDITIONS:
			- populates inventory vector of BinarySearchTrees of DVD's


		NOTES:	DVD objects are solely responsible for knowing how to handle data
				in order to populate data members.

	------------------------------------------------------------------------------------------------*/

	bool setInventory(ifstream& inFile);

	/*------------------------------------------------------------------------------------------------

		Method takes in a file stream and passes the file stream to  a factory class used to create
		Transacton objects and add them to the pending Transaction queue.

		PRECONDITIONS:
			- data must be formatted for Transaction objects

		POSTCONDITIONS:
			- populates pending Transaction queue with Transaction objects

		NOTES:	Transaction objects are solely responsible for knowing how to handle data
				in order to populate data members.

	------------------------------------------------------------------------------------------------*/

	bool setTransactions(ifstream& inFile);

	private:
	
	HashTable* customers = nullptr;									//HashTable to store customers
	vector<BinarySearchTree<DVD>*> inventory;						//vector holding pointers to inventory sets
	queue<Transaction>* pending = nullptr;							//queue of Transaction to be completed
	queue<Transaction>* completed = nullptr;						//queue of completed Transactions
	
};