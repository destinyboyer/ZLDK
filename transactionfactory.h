#pragma once
#include "transaction.h"

class TransactionFactory
{
public:

	static Transaction * createTransaction(string newTrans);

private:

};