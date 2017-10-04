/**
 * \file Game.cpp
 *
 * \author Parker Dodson
 */

#include "stdafx.h"
#include "Game.h"


/**
 * Constructor
 */
CGame::CGame()
{
}


/**
 * Destructor
 */
CGame::~CGame()
{
}


/**
 * Adds item to list of items
 * \param item item to add
 */
void CGame::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}

/*
std::shared_ptr<CItem> CGame::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return nullptr;
}
*/

/*
void CAquarium::Remove(std::shared_ptr<CItem> grabbedItem)
{
	auto loc = find(begin(mItems), end(mItems), grabbedItem);
	if (loc != end(mItems))
	{
		mItems.erase(loc);
	}


	}
*/


/**
* Clear the aquarium data.
*
* Deletes all known items in the aquarium.
*/
void CGame::Clear()
{
	mItems.clear();
}

/** Handle updates for animation
* \param elapsed The time since the last update
*/
void CGame::Update(double elapsed)
{
	for (auto item : mItems)
	{
		item->Update(elapsed);
	}
}


/**
 * OnDraw
 * \param graphics 
 */
void CGame::OnDraw(Gdiplus::Graphics *graphics)
{

}
