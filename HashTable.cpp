//#include "stdafx.h"
#include "HashTable.h"



////////////////////////////////////////////////////////////////////////////////
//																			  //
//							Constructors / Destructors						  //
//																			  //
////////////////////////////////////////////////////////////////////////////////



HashTable::HashTable()
{
	// We point every node slot to null initially. Our philosophy is we 
	// only create a node when we need to store a data object (customer)
	table = new Node*[HASHTABLE_SIZE];
	for (int i = 0; i < HASHTABLE_SIZE; i++)
	{
		this->table[i] = NULL;
	}
}

HashTable::~HashTable()
{
	this->deleteTable();
}



////////////////////////////////////////////////////////////////////////////////
//																			  //
//								Public Methods								  //
//																			  //
////////////////////////////////////////////////////////////////////////////////



bool HashTable::populateTable(ifstream & inFile)
{
	// The file is read into Customer as follows: The first character is removed from
	// inFile to ensure proper checking for end of file. After the check, the char is
	// restored using .unget(). A line from inFile is sent to a string, and converted
	// to a stringstream. This stringstream is sent to the customer in setData().
	Customer* insCustomer;
	string info;
	stringstream ss;
	inFile.get();
	while (!inFile.eof())
	{
		inFile.unget();
		getline(inFile, info);
		ss.str(info);
		ss.clear();
		insCustomer = new Customer();
		insCustomer->setData(ss);
		this->insert(insCustomer);
		inFile.get();
	}
	return true;
}


bool HashTable::retrieve(const int targetID, Customer * retrieved) const
{
	int hashKey = this->hashIndex(targetID);
	Node* cur = table[hashKey];
	while (cur != NULL)
	{
		if (cur->data->getID() == targetID)
		{
			retrieved = cur->data;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

bool HashTable::insert(Customer * toInsert)
{
	int hashKey;
	Node* insNode;

	hashKey = this->hashIndex(toInsert->getID());
	insNode = new Node();
	insNode->data = toInsert;
	// Set next to any current node in slot
	insNode->next = this->table[hashKey];
	this->table[hashKey] = insNode;
	return true;
}



////////////////////////////////////////////////////////////////////////////////
//																			  //
//								Private Methods								  //
//																			  //
////////////////////////////////////////////////////////////////////////////////



int HashTable::hashIndex(const int value) const
{
	return value % HASHTABLE_SIZE;
}

inline void HashTable::deleteTable()
{
	Node* tempNode;
	// For every slot
	for (int i = 0; i < HASHTABLE_SIZE; i++)
	{
		// Keep deleting the first in line, pointing instead to it's next before deletion
		while (table[i] != NULL)
		{
			tempNode = table[i];
			table[i] = table[i]->next;
			// We have to delete each Node's Customer too
			delete tempNode->data;
			delete tempNode;
		}
	}
}
