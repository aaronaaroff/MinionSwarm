/**
 * \file ScoreBoard.h
 *
 * \author Alex Wuillaume
 *
 * Class for scoreboard 
 */

#pragma once
#include "Villain.h"
#include "Minion.h"


/**
 * Class for maintaining the scoreboard
 */
class CScoreBoard
{
public:
	CScoreBoard();
	~CScoreBoard();

	void AddToScore(int pointValue, int pointMultiplier); ///< TODO need to input minion and vilain objects to calculate score.

	void OnDraw(Gdiplus::Graphics *graphics);

	void reset();

	void Update(double elapsed);

	void UpdateScore(CVillain * villian, CMinion * minion);

private:

	/// Arya Starks Score
	int mAryaScore = 0;

	/// Blender SCore
	int mBlenderScore = 0;

	///Poke Ball Score
	int mPokeBallScore = 0;

};

