#include "stdafx.h"
#include "Media.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//								Constructors / Destructors										//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

Media::Media(void)
{
}

Media::~Media(void)
{
	delete date;
	date = nullptr;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//										Public Methods											//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

/*-------------------------------------------------------------------------------------------------

	Sets data members bases on data read from an istream.

-------------------------------------------------------------------------------------------------*/

bool Media::setData(istream& inFile)
{
	bool success = false;

	return success;
}

void Media::display(void) const
{
	cout << "Media Object" << endl;
}

/*-------------------------------------------------------------------------------------------------

	Method adjusts the inventory. Parameter can be positive to add inventory, and
	negative to subtract inventory. If the current inventory + input < -1 the input
	will not be added to the inventory. Returns a bool indicating success.

	POSTCONDITIONS:
		- adjusts the inventory up or down
		- returns a bool indicating success

-------------------------------------------------------------------------------------------------*/

bool Media::adjustInventory(int input)
{
	bool success = false;
	if (inventory + input > -1) {
		inventory += input;
		success = true;
	}
	return success;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//									Getters / Setters											//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

/*-------------------------------------------------------------------------------------------------

	Getter method for inventory.

-------------------------------------------------------------------------------------------------*/

int Media::getInventory(void) const
{
	return this->inventory;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//																								//
//									Overloaded Operators										//
//																								//
//////////////////////////////////////////////////////////////////////////////////////////////////

/*-------------------------------------------------------------------------------------------------

	Overloaded equality operator. Returns whether the calling item has a date equal to the
	parameter.

-------------------------------------------------------------------------------------------------*/

bool Media::operator==(const Media & toCompare) const
{
	return (this->date == toCompare.date);
}

/*-------------------------------------------------------------------------------------------------

	Overloaded equality operator. Returns whether the calling item has a date not equal to the
	parameter. Uses the overloaded equality operator as a helper.

-------------------------------------------------------------------------------------------------*/

bool Media::operator!=(const Media & toCompare) const
{
	return !(*this == toCompare);
}

/*-------------------------------------------------------------------------------------------------

	Overloaded equality operator. Returns whether the calling item has a date less than the
	parameter.

-------------------------------------------------------------------------------------------------*/

bool Media::operator<(const Media & toCompare) const
{
	return (this->date < toCompare.date);
}

/*-------------------------------------------------------------------------------------------------

	Overloaded equality operator. Returns whether the calling item has a date greater than the
	parameter.

-------------------------------------------------------------------------------------------------*/

bool Media::operator>(const Media & toCompare) const
{
	return (this->date > toCompare.date);
}
