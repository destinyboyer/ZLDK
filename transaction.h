#pragma once
#include "store.h"	//Include this here or transaction in store.
using namespace std;

class Transaction
{
public:
	Transaction();
	virtual ~Transaction();

private:
};

class Inventory : public Transaction
{
public:
	Inventory();
	virtual ~Inventory();

private:
};

class History : public Transaction
{
public:
	History();
	virtual ~History();

private:
};

class Borrow : public Transaction
{
public:
	Borrow();
	virtual ~Borrow();

private:
};

class Return : public Transaction
{
public:
	Return();
	virtual ~Return();

private:
};