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

	/** Adds to score
	* \param pointValue the base point val
	* \param pointMultiplier multiplier*/
	void AddToScore(int pointValue, int pointMultiplier);

	/** Draw
	* \param graphics*/
	void OnDraw(Gdiplus::Graphics *graphics);

	/** Resets scoreboard*/
	void reset();

	/** Update score
	* \param villain villain doing the killing
	* \param minion the minion to die*/
	void UpdateScore(CVillain * villain, CMinion * minion);

private:

	/// Arya Starks Score
	int mAryaScore = 0;

	/// Blender SCore
	int mBlenderScore = 0;

	///Poke Ball Score
	int mPokeBallScore = 0;

};

