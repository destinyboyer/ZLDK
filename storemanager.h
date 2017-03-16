#pragma once
#ifndef storemanager_h
#define storemanager_h

#include <vector>
#include <stack>
#include "HashTable.h"
#include "DVD.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
#include "Customer.h"
#include "Transaction.h"
#include "TransactionFactory.h"
#include "BinarySearchTree.h"
#include "dvdfactory.h"

using namespace std;

// This constant can be changed to trees for new media types
const int NUM_OF_INVENTORY_TREES = 3;

class StoreManager
{
public:
	StoreManager(void);
	~StoreManager(void);

//<<<<<<< Updated upstream
	void displayCustomers() const;
	void displayTransactions();
	void displayInventory() const;

	bool setCustomers(ifstream& inFile);
	bool setInventory(ifstream& inFile);
	// This method utilizes a transactionFactory for transaction creation
	bool setTransactions(ifstream& inFile);

private:

	HashTable* customers = nullptr;
	queue<Transaction*> pendingTransactions;
	queue<Transaction*> completeTransactions;
	// Our inventory in this implementation holds 3 DVD trees.
	// These trees are specified by their genre.
	enum BSTMediaType { ComedyDVD, DramaDVD, ClassicDVD };
	vector<BinarySearchTree<DVD>*> inventory;

	// return int 'type' returns the enum for the correct tree.
	DVD* createDVD(istream& inFile, int& type);
};

#endif