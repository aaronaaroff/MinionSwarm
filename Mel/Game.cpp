/**
 * \file Game.cpp
 *
 * \author Parker Dodson
 */

#include "stdafx.h"
#include <memory>
#include "Game.h"
#include "Minion.h"
#include "MainFrm.h"
#include "ItemVisitor.h"

using namespace std;
using namespace Gdiplus;

 /// Game area width in virtual pixels
const static int Width = 1400;

/// Game area height in virtual pixels
const static int Height = 1100;

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


std::shared_ptr<CItem> CGame::HitTest(int x, int y)
{

	auto virtualX = GetVirtualX(x);
	auto virtualY = GetVirtualY(y);
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(virtualX, virtualY))
		{
			return *i;
		}
	}

	return nullptr;
}


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
	mTimeSpawn += elapsed;
	if (mTimeSpawn > 1) {
		auto newMinion = make_shared<CMinion>(this);
		Add(newMinion);
		mTimeSpawn = 0;
	}


	for (auto item : mItems)
	{
		item->Update(elapsed);
	}
}

/**
* Draw the game area
* \param graphics The GDI+ graphics context to draw on
* \param width Width of the client window
* \param height Height of the client window
*/
void CGame::OnDraw(Gdiplus::Graphics *graphics, int width, int height)
{
	
	// Fill the background with black
	SolidBrush brush(Color::Black);
	graphics->FillRectangle(&brush, 0, 0, width, height);

	//
	// Automatic Scaling
	//
	float scaleX = float(width) / float(Width);
	float scaleY = float(height) / float(Height);
	mScale = min(scaleX, scaleY);

	mXOffset = width / 2.0f;
	mYOffset = height / 2.0f;

	graphics->TranslateTransform(mXOffset, mYOffset);
	graphics->ScaleTransform(mScale, mScale);

	// From here on you are drawing virtual pixels
	mTimer.OnDraw(graphics);
	mPlayingArea.OnDraw(graphics, Width, Height);

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}
}

/** Accept a visitor for the collection
* \param visitor The visitor for the collection
*/
void CGame::Accept(CItemVisitor *visitor)
{
	for (auto tile : mItems)
	{
		tile->Accept(visitor);
	}
}

void CGame::ResetGame()
{
}
