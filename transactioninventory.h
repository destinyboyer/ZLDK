/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		2/28/2017

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef inventory_transaction_h
#define inventory_transaction_h

#include "transaction.h"

class inventoryTransaction : public Transaction {
	public:
	inventoryTransaction(void);
	virtual ~inventoryTransaction(void);
	void setData(ifstream, char type);
	void displayTransaction();
	
	
	private:
		char mediaType;
		char genre;
		int releaseMonth;
		int releaseYear;
		string director;
		string title;
		string firstName;
		string lastName;
};

#endif // !inventory_transaction_h
