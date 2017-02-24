#pragma once
#include "dvd.h"
#include <iostream>
using namespace std;

//Still needs to be switched over to dvd from the bank more.

class BSTree
{

public:

	BSTree();
	~BSTree();

	bool Add(DVD *acc); //returns false, account exists

						// retrieve object, first parameter is the ID of the account
						// second parameter holds pointer to found object, NULL if not found
	bool Retrieve(const int &id, DVD * &acc) const;
	bool Contains(const int &id) const;
	// displays the contents of a tree to cout
	void Display() const;
	void Empty();
	bool isEmpty() const;

	//Need other operator overloads?

private:

	struct Node
	{
		DVD *pAcct = nullptr;
		Node *right = nullptr;
		Node *left = nullptr;
	};

	Node *root = nullptr;

	bool insert(Node * &subTree, DVD * acc);
	bool retriever(Node * &subTree, const int &id, DVD * &acc) const;
	bool find(Node * &subTree, const int &id) const;
	void displayer(Node * &currentNode) const;
	void clear(Node * &currentNode);
};