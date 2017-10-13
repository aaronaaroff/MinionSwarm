/**
 * \file ScoreBoard.cpp
 *
 * \author Alex Wuillaume
 */

#include "stdafx.h"
#include "ScoreBoard.h"


/**
 * Constructor
 */
CScoreBoard::CScoreBoard()
{
}


/**
 * Destructor
 */
CScoreBoard::~CScoreBoard()
{
}

void CScoreBoard::AddToScore(int pointValue, int pointMultiplier)
{
	if (pointMultiplier == 1)
	{
		mAryaScore += pointValue;
	}

	else if (pointMultiplier == 2)
	{
		mBlenderScore += (pointValue * pointMultiplier);

	}

	else
	{
		mPokeBallScore += (pointMultiplier * pointValue);
	}
}
