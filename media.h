/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		2/28/2017

	The 

	DVDFactory is an abstract class used to populate a vector of sets. Each index in the vector
	corresponds with a distinct set that holds DVD objects of one type. DVDFactory creates
	DVD objects but it is the sole responsibility of the DVD objects to know how to properly
	handle data in order to populate data members.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef media_h
#define media_h

class Media {

	public:

	virtual Media(void);		//default no-args constructor
	virtual ~Media(void);		//destructor

};

#endif // !media_h
