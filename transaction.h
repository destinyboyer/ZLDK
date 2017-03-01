/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		2/28/2017

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef transaction_h
#define transaction_h

using namespace std;

class Transaction {

	public:
	
	virtual Transaction(void);
	virtual ~Transaction(void);
	
	virtual setData(ifstream, char type));

	private:
	
	char transactionType;
	int id;
	
};

#endif // !transaction_h