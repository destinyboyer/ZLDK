/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		2/28/2017

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef transaction_return_h
#define transaction_return_h

#include "transaction.h"

class Return : public Transaction {
	public:
	Return(void);
	virtual ~Return(void);

	private:
};

#endif // !transaction_return_h
