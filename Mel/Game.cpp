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
#include "NewGame.h"

using namespace std;
using namespace Gdiplus;

 /// Game area width in virtual pixels
const static int Width = 1400;

/// Game area height in virtual pixels
const static int Height = 1100;

/// Arya Name for villain Construction
const wstring AryaName = L"Arya";

/// Blender Name for Villain Construction
const wstring BlendName = L"Blender";

///Poke Ball Name for Villain Construction
const wstring PokeBallName = L"PokeBall";

///orgin point of game 
const double Orgin = 0.0;

///position constant
const double PosOne = -650.0;

///position constant
const double PosTwo = -500.0;

///position constant
const double PosThree = 350.0;

///position constant
const double PosFour = -350.0;

///position constant
const double PosFive = 300.0;

///position constant
const double PosSix = -250.0;

///position constant
const double PosSeven =  575.0;

///position constant
const double PosEight = 0.0;

///position constant
const double PosNine = -350.0;

///position constant
const double PosTen = -150.0;






/** Font stuff
* \return FontFamily*/
FontFamily fontFamily(L"Arial");

/** Font setter
* \return fontFamily*/
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


/**
 * Performs hit test and returns item if you clicked on one
 * \param x coords
 * \param y coords
 * \returns nullptr if no click on item, else a pointer to the item
 */
std::shared_ptr<CItem> CGame::HitTest(double x, double y)
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



/**
 * Removes an item from mItems
 * \param grabbedItem item to remove
 */
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


	// Variable that will be elapsed time for minion spawn 
	double randomVariable = (double)rand() / (2 * RAND_MAX) + .5;

	// Spawns a minion and resets the elapsed time counter
	if (mTimeSpawn > randomVariable) {
		auto newMinion = make_shared<CMinion>(this);
		Add(newMinion);
		mTimeSpawn = 0;
	}

	KillGru();
	if (!mGameOver)
	{
		KillMinions();
	}

	for (auto item : mItems)
	{
		item->Update(elapsed);
	}
}


/**
 * Function that kills the minions touching villains
 */
void CGame::KillMinions()
{
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
						mScoreBoard.UpdateScore(villain, minion);
						mItems.erase(loc);
						return;
					}
				}
			}
		}
	}
}


/**
 * Function that kills Gru if he's touching minion or villain
 */
void CGame::KillGru() 
{
	CDeleteItem vis;
	Accept(&vis);

	CVillainVisitor vis2;
	Accept(&vis2);

	CGetGruCoords vis3;
	Accept(&vis3);

	if (!vis3.Exists())
		return;

	for (auto minion : vis.getMinions()) {
		if (vis3.GetGru()->HitTest(minion->GetX(), minion->GetY())) {
			for (auto loc = mItems.begin(); loc != mItems.end(); loc++)
			{
				if (loc->get() == vis3.GetGru())
				{
					mItems.erase(loc);
					mGameOver = true;
					return;
				}
			}
		}
	}

	for (auto villain : vis2.getMinions()) {
		if (vis3.GetGru()->HitTest(villain->GetX(), villain->GetY())) {
			for (auto loc = mItems.begin(); loc != mItems.end(); loc++)
			{
				if (loc->get() == vis3.GetGru())
				{
					mItems.erase(loc);
					mGameOver = true;
					return;
				}
			}
		}
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

	mXOffset = static_cast<Gdiplus::REAL>(width / 2.0f);
	mYOffset = static_cast<Gdiplus::REAL>(height / 2.0f);
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

	if (mGameOver == true)
	{
		CTimerVisitor stopClock;
		this->Accept(&stopClock);

		

		// Set the font attributes
		FontFamily fontFamily(L"Arial");
		Gdiplus::Font font(&fontFamily, 20);

		SolidBrush green(Color(200, 255, 0));
		graphics->DrawString(L"Gru is Dead!", -1, &font, PointF(-100,-32), &green);
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

//When called will clear all items and redraw them
void CGame::ResetGame()
{
	Clear();
	mResetGameStatus = true;
	mGameOver = false;
	resetScore();
	
	// ResetTimer()
	
}

void CGame::Populate()
{
	auto newgame = make_shared<CNewGame>(this);
	newgame->SetLocation(PosOne, PosTwo);
	Add(newgame);

	auto pokeBall = make_shared<CVillain>(this,PokeBallName);
	pokeBall->SetLocation(PosThree, PosSix);
	Add(pokeBall);

	auto arya = make_shared<CVillain>(this, AryaName);
	arya->SetLocation(Orgin, PosFive);
	Add(arya);

	auto blender = make_shared<CVillain>(this, BlendName);
	blender->SetLocation(PosFour, PosSix);
	Add(blender);

	auto scorePokeBall = make_shared<CVillain>(this, PokeBallName);
	scorePokeBall->SetLocation(PosSeven, PosEight);
	Add(scorePokeBall);

	auto scoreArya = make_shared<CVillain>(this, AryaName);
	scoreArya->SetLocation(PosSeven, PosNine);
	Add(scoreArya);

	auto scoreBlender = make_shared<CVillain>(this, BlendName);
	scoreBlender->SetLocation(PosSeven, PosTen);
	Add(scoreBlender);

	auto gru = make_shared<CGru>(this);
	Add(gru);
}