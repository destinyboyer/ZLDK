#pragma once
#include <string>
#include <vector>
#include "transaction.h"
using namespace std;

class Customer
{
public:
	Customer();
	Customer(int ident, string fName, string lName);
	~Customer();

	void addHistoy(string transaction);

private:
	int id;
	string cFName;
	string cLName;
	vector<string> history;
};
