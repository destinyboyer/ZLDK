/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		2/28/2017

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef transaction_inventory_h
#define transaction_inventory_h

#include "transaction.h"

class Inventory : public Transaction {
	public:
	Inventory(void);
	virtual ~Inventory(void);

	private:
};

#endif // !transaction_inventory_h
