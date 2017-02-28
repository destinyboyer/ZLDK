/*-------------------------------------------------------------------------------------------------


-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef  store_h
#define store_h

#include "dvd.h"
#include "customer.h"
#include "bstree.h"
#include "hashtable.h"
using namespace std;

class Store
{
public:
	Store();
	//Other constructors
	~Store();

	void buildInventory(/*BTree or file of dvds*/);
	bool Borrow(/*something DVD*/);
	bool Return(/*something DVD*/);
	void Inventory();
	bool History(int customerID);
	bool addDVD(const DVD* &movie) const;
	

private:
	HashTable customers;	//Hash table of Customer*
	BSTree database;		//BTree or something of DVD
};

#endif