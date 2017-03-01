#pragma once
#include <string>
using namespace std;

enum Genre{F, D, C};
struct Date 
{
	int month;
	int year;
};

class DVD
{
public:
	DVD();
	//Other Constructors
	virtual ~DVD();

	void display(); //Override function, Do I need virtual on this one too?
	bool adjustInventory(int num);

private:
	Genre type;
	int inventory;
	string dFName;
	string dLName;
	string title;
};

class Classic : public DVD
{
public:
	Classic();
	virtual ~Classic();

	virtual void display();

private:
	string aFName;
	string aLName;
	Date release;
};

//Do we need different for comedy and drama?
class Drama : public DVD
{
public:
	Drama();
	virtual ~Drama();

	virtual void display();

private:
	int year;
};

class Comedy : public DVD
{
public:
	Comedy();
	virtual ~Comedy();

	virtual void display();

private:
	int year;

};