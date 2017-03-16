
#include "TransactionFactory.h"

Transaction* TransactionFactory::createTransaction(istream& inFile, queue<Transaction*>)
{
	Transaction* returnTrans = nullptr;
	char transType;
	bool success = false;
	string tempString;

	transType = inFile.get();
	switch (transType)
	{
	case 'I':
	case 'H':
		returnTrans = new Transaction();
		break;
	case 'B':
	case 'R':
		returnTrans = new InventoryTransaction();
		break;
	default:
		returnTrans = NULL;
		getline(inFile, tempString);
	}
	if (returnTrans != NULL)
	{
		success = returnTrans->setData(inFile, transType);
	}
	if (success)
	{
		return returnTrans;
	}
	else
	{
		return nullptr;
	}
}
