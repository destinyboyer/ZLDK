#pragma once
#ifndef customer_h
#define customer_h

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Customer
{
public:
	Customer(void);
	~Customer(void);
	
	void setData(istream& inFile);
	//void displayHistory(void) const;
	void displayCustomer(void) const;
	//void displayHolding(void) const;
	//void addTransaction(const Transaction& toAdd);
	//void borrowMedia(Transaction& transaction);
	//void returnMedia(Transaction& transaction);

	int getID(void) const;
	//string getFistName(void) const;
	//string getLastName(void) const;

	//bool setID(int input);
	//bool setFirstName(string input);
	//bool setLastName(string input);

	//Customer& operator=(const Customer& toCopy);
	
private:
	int ID = 0;
	string firstName = "";
	string lastName = "";
	//queue<Transaction> history;
	//vector<Media> holding;
	
};

#endif