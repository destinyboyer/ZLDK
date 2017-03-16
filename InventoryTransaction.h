#pragma once
#ifndef inventorytransaction_h
#define inventorytransaction_h

#include <string>
#include "Transaction.h"
#include "Date.h"

using namespace std;

class InventoryTransaction : public Transaction
{
public:
	InventoryTransaction();
	InventoryTransaction(InventoryTransaction& toCopy);
	~InventoryTransaction();

	bool setData(istream& inFile, char type); // needs implementation
	void displayTransaction(void) const; // needs implementation

	
	char getMediaType(void) const;
	char getGenre(void) const;
	string getDirector(void) const;
	string getTitle(void) const;
	string getFirstName(void) const;
	string getLastName(void) const;
	int getYear(void) const;
	int getMonth(void) const;
	int getDay(void) const;

	/*------------------------------------------------------------------------------------------------
	Setter method for mediaType. Returns a bool indicating success.
	PRECONDITIONS:
	- input cannot be an empty character
	POSTCONDITIONS:
	- sets mediaType to input
	------------------------------------------------------------------------------------------------*/

	bool setMediaType(char input);

	/*------------------------------------------------------------------------------------------------
	Setter method for genre. Returns a bool indicating success.
	PRECONDITIONS:
	- input cannot be an empty character
	POSTCONDITIONS:
	- sets genre to input
	------------------------------------------------------------------------------------------------*/

	bool setGenre(char input);

	/*------------------------------------------------------------------------------------------------
	Setter method for director. Returns a bool indicating success.
	PRECONDITIONS:
	- input cannot be an empty string
	POSTCONDITIONS:
	- sets director to input
	------------------------------------------------------------------------------------------------*/

	bool setDirector(string input);

	/*------------------------------------------------------------------------------------------------
	Setter method for title. Returns a bool indicating success.
	PRECONDITIONS:
	- input cannot be an empty string
	POSTCONDITIONS:
	- sets title to input
	------------------------------------------------------------------------------------------------*/

	bool setTitle(string input);

	/*------------------------------------------------------------------------------------------------
	Setter method for actorLastName. Returns a bool indicating success.
	PRECONDITIONS:
	- input cannot be an empty string
	POSTCONDITIONS:
	- sets actorLastName to input
	------------------------------------------------------------------------------------------------*/

	bool setLastName(string input);

	/*------------------------------------------------------------------------------------------------
	Setter method for actorFirstName. Returns a bool indicating success.
	PRECONDITIONS:
	- input cannot be an empty string
	POSTCONDITIONS:
	- sets actorFirstName to input
	------------------------------------------------------------------------------------------------*/

	bool setFirstName(string input);

	bool setYear(int input);
	bool setMonth(int input);
	bool setDay(int input);

	InventoryTransaction& operator=(const InventoryTransaction& toCopy);



private:
	char mediaType = ' ';
	char genre = ' ';
	string director = "<director>";
	string title = "<title>";
	string actorFirstName = "<actorFirstName>";
	string actorLastName = "<actorLastName>";
	Date date = Date();
};



#endif