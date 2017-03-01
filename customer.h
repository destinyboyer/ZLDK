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
	void setID(int);
	void getID();
	void setFirstName(string);
	string getFirstName();
	void setLastName(string);
	string getLastName();
	void setData(istream &);
	void displayHistory();
	void addTransaction(transaction);
	string displayCustomer();
	void borrow(transaction);
	void return(transaction);
	
private:
	int id;
	string cFName;
	string cLName;
	queue<transaction> history;
	vector<media> holding;
};
