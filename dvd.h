#pragma once
#ifndef dvd_h
#define dvd_h

#include <string>
#include <iostream>
#include "Media.h"

using namespace std;

class DVD : public Media
{
public:
	DVD(void);
	virtual ~DVD(void);
	//DVD(DVD& toCopy);

	virtual bool setData(istream& inFile);
	virtual void display(void) const;

	char getType(void) const;
	string getTitle(void) const;
	string getDirector(void) const;
	int getYear(void) const;

	bool setType(char input);
	bool setTitle(string input);
	bool setDirector(string input);
	bool setYear(int input);

	virtual bool operator==(const DVD& toCompare) const;
	virtual bool operator!=(const DVD& toCompare) const;
	virtual bool operator<(const DVD& toCompare) const;
	virtual bool operator>(const DVD& toCompare) const;
	//virtual DVD& operator=(const DVD& toCopy) const;

protected:
	char type = ' ';
	string title = "";
	string director = "";
};

#endif