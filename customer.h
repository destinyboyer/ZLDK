/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/1/2017

	This class represents a customer object. Each object stores the customer's first and last
	names, a unique customer ID, a history of the customer's transactions, and a queue of
	which media items the customer is holding (still has checked out). This class has the
	functionality to take in a data stream with the method setData() in order to populate its
	data members. The method displayCustomer() will neatly print a customer object's
	information to the console.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef customer_h
#define customer_h

#include <string>
#include <vector>
#include <queue>
#include <iostream>

#include "media.h"
#include "transaction.h"
#include "inventoryTransaction.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"

using namespace std;

class Customer
{
public:
	Customer(void);
	Customer(const Customer& toCopy);
	~Customer(void);
	
	bool setData(istream& inFile);
	void displayHistory(void);
	void displayCustomer(void) const;
	void displayHolding(void);
	void addTransaction(const Transaction& toAdd);
	void borrowMedia(InventoryTransaction& transaction);
	void returnMedia(InventoryTransaction& transaction);

	int getID(void) const;
	string getFistName(void) const;
	string getLastName(void) const;

	bool setID(int input);
	bool setFirstName(string input);
	bool setLastName(string input);

	Customer& operator=(const Customer& toCopy);
	
private:
	int ID = 0;
	string firstName = "";
	string lastName = "";
	vector<Transaction> history;
	vector<DVD> holding;
	
};

#endif