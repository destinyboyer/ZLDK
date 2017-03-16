//#include "stdafx.h"
#include "StoreManager.h"


////////////////////////////////////////////////////////////////////////////////
//																			  //
//							Constructors / Destructors						  //
//																			  //
////////////////////////////////////////////////////////////////////////////////



StoreManager::StoreManager()
{
}


StoreManager::~StoreManager()
{
}

void StoreManager::displayCustomers() const
{
	cout << "<displayCustomers>" << endl;
}

void StoreManager::displayTransactions()
{
	// This is not ideal - should change if included in final project
	queue<Transaction*> movedTransactions;
	int size;
	// Copy over and print
	size = this->pendingTransactions.size();
	for (int i = 0; i < size; i++)
	{
		movedTransactions.push(this->pendingTransactions.front());
		this->pendingTransactions.front()->displayTransaction();
		this->pendingTransactions.pop();
	}
	// Copy back
	for (int i = 0; i < size; i++)
	{
		this->pendingTransactions.push(movedTransactions.front());
		movedTransactions.pop();
	}
}

void StoreManager::displayInventory() const
{
	cout << "~ ComedyDVD BST Display ~" << endl;
	this->inventory[ComedyDVD]->display();
	cout << "~ DramaDVD BST Display ~" << endl;
	this->inventory[DramaDVD]->display();
	cout << "~ ClassicDVD BST Display ~" << endl;
	this->inventory[ClassicDVD]->display();
}



////////////////////////////////////////////////////////////////////////////////
//																			  //
//								Public Methods								  //
//																			  //
////////////////////////////////////////////////////////////////////////////////



bool StoreManager::setCustomers(ifstream & inFile)
{
	if (customers != NULL)
	{
		delete customers;
	}
	customers = new HashTable();
	customers->populateTable(inFile);
	return false;
}

bool StoreManager::setInventory(ifstream & inFile)
{
	// Delete any current trees safely
	while (this->inventory.size() > 0)
	{
		delete this->inventory[inventory.size() - 1];
		inventory.pop_back();
	}

	BinarySearchTree<DVD>* curTree;
	for (int i = 0; i < NUM_OF_INVENTORY_TREES; i++)
	{
		curTree = new BinarySearchTree<DVD>();
		this->inventory.push_back(curTree);
	}

//<<<<<<< Updated upstream
//	DVD* InsertDVD;
//	string info;
//	stringstream ss;
//	int insertTree;
//	inFile.get();
//	while (!inFile.eof())
//	{
//		inFile.unget();
//		getline(inFile, info);
//		ss.str(info);
//		ss.clear();
//		InsertDVD = createDVD(ss, insertTree);
//		if (InsertDVD != NULL)
//		{
//			if (!this->inventory[insertTree]->insert(InsertDVD))
//			{
//				// if insert returns false, that means we are dealing with a duplicate movie
//				Media* baseMedia, cur;
//				this->inventory[insertTree]->retrieve(*InsertDVD, baseMedia);
//				// THIS IS WHERE YOU LEFT OFF
//			}
//			// if we *don't* enter the above 'if body', then we have successfully inserted (not a duplicate)
//		}
//		else
//		{
//			cout << "\n\tERROR: Invalid movie entry:. The inventory request has been deleted.\n" << endl;
//
//		}
//		inFile.get();
//	}

	DVDFactory factory;
	factory.buildInventory(inFile, inventory);

	//DVD* InsertDVD;
	//string info;
	//stringstream ss;
	//int insertTree;
	//inFile.get();
	//while (!inFile.eof())
	//{
	//	inFile.unget();
	//	getline(inFile, info);
	//	ss.str(info);
	//	ss.clear();
	//	InsertDVD = createDVD(ss, insertTree);
	//	if (InsertDVD != NULL)
	//	{
	//		if (!this->inventory[insertTree]->insert(InsertDVD))
	//		{
	//			// if insert returns false, that means we are dealing with a duplicate movie
	//			Media* baseMedia, cur;
	//			this->inventory[insertTree]->retrieve(*InsertDVD, baseMedia);
	//			// THIS IS WHERE YOU LEFT OFF
	//		}
	//	}
	//	else
	//	{
	//		cout << "\n\tERROR: Invalid movie entry:. The inventory request has been deleted.\n" << endl;

	//	}
	//	inFile.get();
	//}


	return true;
}

bool StoreManager::setTransactions(ifstream & inFile)
{
	// Our do-while loop creates transactions using a static method from TransactionFactory
	// TO DO: Needs to stop upon .eof
	Transaction* transPtr = nullptr;
	// Could be converted to while(true)
	do {
		transPtr = TransactionFactory::createTransaction(inFile, this->pendingTransactions);
		if (transPtr != NULL)
		{
			this->pendingTransactions.push(transPtr);
		}
	} while (!inFile.eof());

	return true;
}



////////////////////////////////////////////////////////////////////////////////
//																			  //
//								Private Methods								  //
//																			  //
////////////////////////////////////////////////////////////////////////////////



DVD * StoreManager::createDVD(istream & inFile, int& type)
{
	DVD* returnDVD = nullptr;
	char DVDType = inFile.get();
	inFile.unget();
	switch (DVDType)
	{
	case 'F':
		returnDVD = new Comedy();
		returnDVD->setData(inFile);
		type = ComedyDVD;
		break;
	case 'D':
		returnDVD = new Drama();
		returnDVD->setData(inFile);
		type = DramaDVD;
		break;
	case 'C':
		returnDVD = new Classic();
		returnDVD->setData(inFile);
		type = ClassicDVD;
		break;
	default:
		// Recieved faulty type
		break;
	};
	return returnDVD;
}

