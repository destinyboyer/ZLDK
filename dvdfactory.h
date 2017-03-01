/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/1/2017

	DVDFactory is an abstract class used to populate a vector of BinarySearchTrees. Each index
	in the vector corresponds with a distinct BinarySearchTree that holds DVD objects of one type.
	DVDFactory creates DVD objects but it is the sole responsibility of the DVD objects to know
	how to properly handle data in order to populate data members.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef dvdfactory_h
#define dvdfactory_h

#include <iostream>
#include <set>
#include <vector>
#include "dvd.h"
#include "hashtable.h"
#include "binarysearchtree.h"

using namespace std;

class DVDFactory {

	public:

	/*------------------------------------------------------------------------------------------------

		Method takes in a file stream and a vector of BinarySearchTree pointers. The method creates
		DVD objects based on the type of DVD read from the file stream and then inserts the object
		into a BinarySearchTree that corresponds with that DVD type.

		PRECONDITIONS:
			- data must be formatted for DVD objects

		POSTCONDITIONS:
			- populates distinct sets based on the type of DVD's created

		NOTES:	DVD objects are solely responsible for knowing how to handle data
				in order to populate data members.

	------------------------------------------------------------------------------------------------*/

	void createTransactions(ifstream& inFile, vector<BinarySearchTree<DVD>*> inventory);

};

#endif // !dvdfactory_h
