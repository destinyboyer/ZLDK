// CSS343_Lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StoreManager.h"
#include <iostream>
#include <fstream>

int main()
{
	StoreManager store = StoreManager();
	ifstream customerInFile("data4customers.txt");
	ifstream movieInFile("data4movies.txt");
	

	// Reading in customers
	if (!customerInFile)
	{
		cout << "Customer file could not be opened." << endl;
		return 1;
	}
	store.setCustomers(customerInFile);


	// Reading in inventory
	if (!movieInFile)
	{
		cout << "Movie file could not be opened." << endl;
		return 1;
	}
	store.setInventory(movieInFile);



	
    return 0;
}

