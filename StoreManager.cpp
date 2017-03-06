#include "stdafx.h"
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

	BinarySearchTree<Media>* curTree;
	for (int i = 0; i < NUM_OF_INVENTORY_TREES; i++)
	{
		curTree = new BinarySearchTree<Media>();
		this->inventory.push_back(curTree);
	}

	DVD* InsertDVD;
	string info;
	stringstream ss;
	int insertTree;
	inFile.get();
	while (!inFile.eof())
	{
		inFile.unget();
		getline(inFile, info);
		ss.str(info);
		ss.clear();
		InsertDVD = createDVD(ss, insertTree);
		if (InsertDVD != NULL)
		{
			if (!this->inventory[insertTree]->insert(InsertDVD))
			{
				// if insert returns false, that means we are dealing with a duplicate movie
				Media* baseMedia, cur;
				this->inventory[insertTree]->retrieve(*InsertDVD, baseMedia);
				// THIS IS WHERE YOU LEFT OFF
			}
		}
		else
		{
			cout << "\n\tERROR: Invalid movie entry:. The inventory request has been deleted.\n" << endl;

		}
		inFile.get();
	}


	return false;
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

