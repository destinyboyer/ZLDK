/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/1/2017

	High-level parent class for Media types for the store. Increases extensibility.

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
