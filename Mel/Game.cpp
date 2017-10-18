/**
 * \file Game.cpp
 *
 * \author Parker Dodson
 */

#include "stdafx.h"
#include <memory>
#include <vector>
#include "Game.h"
#include "Item.h"
#include "Gru.h"
#include "Villain.h"
#include "Minion.h"
#include "MainFrm.h"
#include "DeleteItem.h"
#include "MinionVisitor.h"
#include "VillainVisitor.h"
#include "GetGruCoords.h"
#include "DeleteItem.h"
#include "TimerVisitor.h"
#include "Timer.h"

using namespace std;
using namespace Gdiplus;

 /// Game area width in virtual pixels
const static int Width = 1400;

/// Game area height in virtual pixels
const static int Height = 1100;

FontFamily fontFamily(L"Arial");
Gdiplus::Font font(&fontFamily, 16);

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



void CGame::Remove(std::shared_ptr<CItem> grabbedItem)
{
	auto loc = find(begin(mItems), end(mItems), grabbedItem);
	if (loc != end(mItems))
	{
		mItems.erase(loc);
	}
}



/**
* Clear the game data.
*
* Deletes all known items in the game.
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

	
	CDeleteItem vis;
	Accept(&vis);

	CVillainVisitor vis2;
	Accept(&vis2);

	for (CVillain* villain : vis2.getMinions())
	{
		for (auto minion : vis.getMinions()) {
			if (villain->HitTest(minion->GetX(), minion->GetY())) {
				for (auto loc = mItems.begin(); loc != mItems.end(); loc++)
				{
					if (loc->get() == minion)
					{
						mItems.erase(loc);
						break;
					}
				}
			}
		}
	}

	CGetGruCoords vis3;
	Accept(&vis3);

	for (auto minion : vis.getMinions()) {
		if (vis3.GetGru()->HitTest(minion->GetX(), minion->GetY())) {
			for (auto loc = mItems.begin(); loc != mItems.end(); loc++)
			{
				if (loc->get() == minion)
				{
					mItems.erase(loc);
					break;
				}
			}
		}
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
	//mTimer.Draw(graphics);
	mPlayingArea.OnDraw(graphics, Width, Height);
	mScoreBoard.OnDraw(graphics);

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}

	//if (mGame.GetGameOver() == true)
	//{

	CTimerVisitor stopClock;
	this->Accept(&stopClock);

	SolidBrush green(Color(0, 64, 0));
	graphics->DrawString(L"Under the Sea!", -1, &font, PointF(0, 0), &green);
	//}

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

//When called will clear all items and redraw them
void CGame::ResetGame()
{
	Clear();
	mResetGameStatus = true;
	// ReScoreboard();
	// ResetTimer()
	//No scoreboard support right now on the reset game
}


/*
void CGame::DeleteItem(std::shared_ptr<CItem> item)
{
	auto loc = find(::begin(mItems), ::end(mItems), item);
	if (loc != ::end(mItems))
	{
		mItems.erase(loc);
	}
}*/
