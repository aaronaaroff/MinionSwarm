/**
 * \file Game.cpp
 *
 * \author Parker Dodson
 */

#include "stdafx.h"
#include <memory>
#include "Game.h"
#include "Item.h"
#include "Minion.h"
#include "MainFrm.h"
#include "ItemVisitor.h"
#include "DeleteItem.h"
#include "TimerVisitor.h"
#include "Timer.h"
#include "AryaStark.h"
#include "Blender.h"
#include "PokeBall.h"
#include "Gru.h"
#include "Villain.h"
#include "ScoreBoard.h"
#include "NewGame.h"
#include "ChildView.h"


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


	// Set the font attributes
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 64);

	

	SolidBrush green(Color(255, 255, 0));
	graphics->DrawString(L"Gru is Dead!", -1, &font, PointF(-220,-32), &green);
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

/*
void CGame::Populate()
{
	mGame.SetResetGameStatus(false);

	std::shared_ptr<CTimer> newTimer(game);
	Add(newTimer);

	std::shared_ptr<CNewGame> newgame(game);
	newgame->SetLocation(-650, -500);
	Add(newgame);

	std::shared_ptr<CGru> gru(game);
	Add(gru);

	std::shared_ptr<CPokeBall> pokeBall(game);
	pokeBall->SetLocation(350.0, -250.0);
	Add(pokeBall);

	std::shared_ptr<CAryaStark> arya(game);
	arya->SetLocation(0.0, 300.0);
	Add(arya);

	std::shared_ptr<CBlender> blender(game);
	blender->SetLocation(-350.0, -250.0);
	Add(blender);

	std::shared_ptr<CPokeBall> scorePokeBall(game);
	scorePokeBall->SetLocation(750.0, 100.0);
	Add(scorePokeBall);

	std::shared_ptr<CAryaStark> scoreArya(game);
	scoreArya->SetLocation(750.0, -300.0);
	Add(scoreArya);

	std::shared_ptr<CBlender> scoreBlender(game);
	scoreBlender->SetLocation(750.0, -100.0);
	Add(scoreBlender);

}
*/