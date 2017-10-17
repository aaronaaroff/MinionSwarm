/**
 * \file ScoreBoard.cpp
 *
 * \author Alex Wuillaume
 */


#include "stdafx.h"
#include "ScoreBoard.h"
#include <string>

using namespace std;
using namespace Gdiplus;

/// X Location for all Score Board Trackers
const int scoreXLocation = 650;

///Y Locations for different Villains Score Board Trackers
const int aryaScoreYLocation = -300;

const int blenderScoreYLocation = -100;

const int pokeBallScoreYLocation = 100;

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

void CScoreBoard::OnDraw(Gdiplus::Graphics *graphics)
{
	//getting all scores as strings
	string aryaScoreStr = to_string(mAryaScore);
	string blendScoreStr = to_string(mBlenderScore);
	string pokeScoreStr = to_string(mPokeBallScore);

	//Converting to wstring
	wstring badLadyScore(aryaScoreStr.begin(), aryaScoreStr.end());
	const wchar_t* s1 = badLadyScore.c_str();

	wstring juicerScore(blendScoreStr.begin(), blendScoreStr.end());
	const wchar_t* s2 = juicerScore.c_str();

	wstring pokemonBallScore(pokeScoreStr.begin(), pokeScoreStr.end());
	const wchar_t* s3 = pokemonBallScore.c_str();

	// Set the font attributes
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 18);

	// Draws the time in the timer rectangle
	SolidBrush green(Color(0, 128, 0));
	graphics->DrawString(s1,  // String to draw
		-1,         // String length, -1 means it figures it out on its own
		&font,      // The font to use
		PointF(scoreXLocation, aryaScoreYLocation),   // Where to draw (top left corner)
		&green);    // The brush to draw the text with

	
	graphics->DrawString(s2,  // String to draw
		-1,         // String length, -1 means it figures it out on its own
		&font,      // The font to use
		PointF(scoreXLocation, blenderScoreYLocation),   // Where to draw (top left corner)
		&green);    // The brush to draw the text with


	graphics->DrawString(s3,  // String to draw
		-1,         // String length, -1 means it figures it out on its own
		&font,      // The font to use
		PointF(scoreXLocation, pokeBallScoreYLocation),   // Where to draw (top left corner)
		&green);    // The brush to draw the text with

}

void CScoreBoard::reset()
{
	mAryaScore = 0;
	mBlenderScore = 0;
	mPokeBallScore = 0;

}

void CScoreBoard::Update(double elapsed)
{

}
