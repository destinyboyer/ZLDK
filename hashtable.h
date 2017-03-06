////////////////////////////////////////////////////////////////////////////////
// NOTE:
// This version of HashTable is *NOT* templatized. There were some annoyances
// with implementing as a templatized HashTable. For instance, there was no way
// to determine what value should be taken from the template object to determine
// its hash key. With Customer, we use getID. But we cannot/should not assume
// that any object used as the template will have the getID function.
////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef hashtable_h
#define hashtable_h

#include "Customer.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

struct Node;

const int HASHTABLE_SIZE = 10;

class HashTable
{
public:
	HashTable();
	~HashTable();

	bool populateTable(ifstream& inFile);
	bool retrieve(const int targetID, Customer* retrieved) const;
	bool insert(Customer* toInsert);

private:
	Node** table;

	int hashIndex(const int value) const;
	void deleteTable();
};

struct Node
{
	Customer* data = NULL;
	Node* next = NULL;
};

#endif