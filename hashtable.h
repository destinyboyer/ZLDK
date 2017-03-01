/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/1/2017

	Templatized HashTable class. Class has functionality to populate a HashTable, retrieve items,
	and insert items.

	NOTES:	All responsibility for handling a filestream to populate an Object's data members
			is the responsibility of the Object.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef hashtable_h
#define hashtable_h

using namespace std;

template<class Object>
class HashTable {

	public:
	
	HashTable(void);		//default no-args constructor
	~HashTable(void);		//destructor
	
	/*------------------------------------------------------------------------------------------------

		Method takes in a file stream and passes the file stream to the objects to populate
		objects and then insert them into the HashTable.

		PRECONDITIONS:
			- data must be formatted for Objects

		POSTCONDITIONS:
			- populates HashTable with objects

		NOTES:	Objects are solely responsible for knowing how to handle data
			in order to populate data members.

	------------------------------------------------------------------------------------------------*/

	bool populateTable(ifstream& inFile, HashTable* toPopulate);

	/*------------------------------------------------------------------------------------------------

		Method takes in a target Object and finds the corresponding Object in the HashTable. If
		the Object is found retrieved is set equal to the object.

		POSTCONDITIONS:
			- sets retrieved to retrieved Object.

		NOTES:	Objects are solely responsible equality comparisons

	------------------------------------------------------------------------------------------------*/

	Object* retrieve(const Object* target, Object* retrieved) const;

	/*------------------------------------------------------------------------------------------------

		Method takes in an Object and inserts it into the table. Returns a bool indicating success.

		PRECONDITIONS:
			- toInsert cannot be nullptr

		POSTCONDITIONS:
			- inserts toInsert into HashTable

	------------------------------------------------------------------------------------------------*/

	bool insert(Object* toInsert);

};


#endif // !hashtable_h