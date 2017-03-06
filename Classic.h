#pragma once
#ifndef classic_h
#define classic_h

#include "DVD.h"

using namespace std;

class Classic : public DVD
{
public:
	Classic();
	~Classic();

	bool setData(istream& inFile);
	void display(void);

	//bool operator==(const DVD& toCompare) const;
	//bool operator!=(const DVD& toCompare) const;
	//bool operator<(const DVD& toCompare) const;
	//bool operator>(const DVD& toCompare) const;
	//bool operator=(const DVD& toCopy) const;

	string getActor(void) const;
	int getMonth(void) const;

	bool setActor(string input);
	bool setMonth(int input);

	//Classic& operator=(const Classic& toCopy);



private:
	string majorActor = "";
	Classic* nextIdentical;
};

#endif