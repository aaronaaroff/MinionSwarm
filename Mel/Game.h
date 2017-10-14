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

	///Timer Object to keep track of In Game Time
	///CTimer mTimer;

	///Score Board Object used to track villian points
	CScoreBoard mScoreBoard;

	///All of the Itmes that will populate the Game
	std::vector<std::shared_ptr<CItem> > mItems;

	///Green outline of play area
	CPlayingArea mPlayingArea;

	///Scale for Virtual pixels
	double mScale = 1;

	///X offset for virtual pixels
	double mXOffset = 0;

	///Y offset for virtual pixels
	double mYOffset = 0;

	///Time since last spawn
	double mTimeSpawn = 0;

public:

	CGame();

	virtual ~CGame();

	void Add(std::shared_ptr<CItem> item);

	//void Add(std::shared_ptr<CItem> item);

	//void Remove(std::shared_ptr<CItem> grabbedItem);

	std::shared_ptr<CItem> HitTest(int x, int y);

	void Clear();

	virtual void Update(double elapsed);

	void OnDraw(Gdiplus::Graphics * graphics, int width, int height);

	void Accept(CItemVisitor * visitor);

	int GetVirtualX(double x)
	{
		x = (x - mXOffset) / mScale;
		return x;
	}

	int GetVirtualY(double y)
	{
		y = (y - mYOffset) / mScale;
		return y;
	}

	void ResetGame();

	void DeleteItem(std::shared_ptr<CItem> item);


};

