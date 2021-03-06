/**
 * \file Game.h
 *
 * \author Parker Dodson
 *
 *  This File sets up the CGame Class.
 * This is the system class for the Game Minion Swarm 
 */

#pragma once

#include <memory>
#include <vector>
#include "ScoreBoard.h"
#include "Item.h"
#include "Timer.h"
#include "PlayingArea.h"
#include "ItemVisitor.h"

/**
 * Game class, similar to Aquarium
 */
class CGame
{
private:

	///Score Board Object used to track villian points
	CScoreBoard mScoreBoard;

	///All of the Itmes that will populate the Game
	std::vector<std::shared_ptr<CItem> > mItems;

	///Green outline of play area
	CPlayingArea mPlayingArea;

	///Scale for Virtual pixels
	Gdiplus::REAL mScale = 1;

	///X offset for virtual pixels
	Gdiplus::REAL mXOffset = 0;

	///Y offset for virtual pixels
	Gdiplus::REAL mYOffset = 0;

	///Time since last spawn
	double mTimeSpawn = 0;

	///True when new game is pressed
	bool mResetGameStatus = false;

	///True when gru dies
	bool mGameOver = false;

public:

	CGame();

	/** Gets status of resetgame
	* \return status */
	bool GetResetGameStatus() { return mResetGameStatus; }

	/** Sets status of resetgame
	* \param status */
	void SetResetGameStatus(bool status) { mResetGameStatus = status; }

	virtual ~CGame();

	void Add(std::shared_ptr<CItem> item);

	std::shared_ptr<CItem> HitTest(double x, double y);

	void Remove(std::shared_ptr<CItem> grabbedItem);

	void Clear();

	virtual void Update(double elapsed);

	void KillMinions();

	void KillGru();

	void OnDraw(Gdiplus::Graphics * graphics, int width, int height);

	void Accept(CItemVisitor * visitor);

	/** Gets virtual x
	* \param x
	* \return virtual x */
	virtual double GetVirtualX(double x)
	{
		x = (x - mXOffset) / mScale;
		return x;
	}

	/** Gets virtual y
	* \param y
	* \return virtual y */
	virtual double GetVirtualY(double y)
	{
		y = (y - mYOffset) / mScale;
		return y;
	}

	/** Resets the game*/
	void ResetGame();

	/** Populates the game*/
	void Populate();

	/** Resets the scoreboard*/
	void resetScoreboared() { mScoreBoard.reset(); }

	/** Gets game over status
	* \return virtual x */
	bool GetGameOver() { return mGameOver; }

	/** Gets virtual x
	* \param status*/
	void SetGameOver(bool status) { mGameOver = status; }

	/** Calls Reset on the Scoreboard */
	void resetScore() { mScoreBoard.reset(); }

	/** Get Sum of Points*/
	int getTotalScore() { return mScoreBoard.getTotalScore(); }
};

