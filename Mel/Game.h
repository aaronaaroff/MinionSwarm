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
//#include "Timer.h"


class CGame
{
private:
	///Timer Object to keep track of In Game Time
	///CTimer mTimer;

	///Score Board Object used to track villian points
	CScoreBoard mScoreBoard;

	///All of the Itmes that will populate the Game
	std::vector<std::shared_ptr<CItem> > mItems;

public:


	CGame();

	virtual ~CGame();

	void Add(std::shared_ptr<CItem> item);

	void OnDraw(Gdiplus::Graphics * graphics);

	//void Add(std::shared_ptr<CItem> item);

	//void Remove(std::shared_ptr<CItem> grabbedItem);

	//std::shared_ptr<CITem> HitTest(int x, int y);

	void Clear();

	virtual void Update(double elapsed);

};

