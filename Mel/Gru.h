#pragma once
#include "Item.h"

class CGru :
	public CItem
{
public:

	CGru::CGru(CGame *game);
	virtual ~CGru();

	/// Default constructor (disabled)
	CGru() = delete;

	/// Copy constructor (disabled)
	CGru(const CGru &) = delete;
};

