/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		2/28/2017

-------------------------------------------------------------------------------------------------*/
#pragma once
#include "store.h"	//Include this here or transaction in store.


using namespace std;

class Transaction
{
public:
	Transaction(void);
	virtual ~Transaction(void);

private:
};

class History : public Transaction
{
public:
	History(void);
	virtual ~History(void);

private:
};
