/**
* \file Minion.cpp
*
* \author Tyler Gasper


*/#include "stdafx.h"
#include <math.h>
#include "Minion.h"
#include "Vector.h"
#include "GetGruCoords.h"
#include "FlockingVisitor.h"
#include "Game.h"

using namespace std;
using namespace Gdiplus;


/// Image directory name 
const wstring ImagesDirectory = L"images/";

/// Image of the standard minion
const wstring JerryMinion = L"jerry.png";

/// Mutant speed
const int MutantSpeed = 200;

///Standard Minion speed
const int MinionSpeed = 100;

/// Y offset 
const int OffsetUp = -450;




/** Constructor
* \param city The city this is a member of
*/
CMinion::CMinion(CGame *game) : CItem(game, ImagesDirectory + JerryMinion)
{
	double randomVariable = (double)rand() / RAND_MAX;
	if (randomVariable > .85)
	{
		mState = Mutant;
		mSpeedX = MutantSpeed;
		mSpeedY = MutantSpeed;
		mMinionSpeed = MutantSpeed;
		mPoints = 2;

	}
	else if (randomVariable > .5)
	{
		mState = Stuart;
		mSpeedX = MinionSpeed;
		mSpeedY = MinionSpeed;
		mMinionSpeed = MinionSpeed;
		mPoints = 1;
	}
	else
	{
		mState = Jerry;
		mSpeedX = MinionSpeed;
		mSpeedY = MinionSpeed;
		mMinionSpeed = MinionSpeed;
		mPoints = 1;

	}

	double xLocation = (500 - 77/2 )* (((double)rand() - (RAND_MAX/2))  / (RAND_MAX / 2));
	if (mState == Stuart)
	{
		setImage(ImagesDirectory + mMinionStuartImage);
	}

	else if (mState == Jerry)
	{
		setImage(ImagesDirectory + mMinionJerryImage);
	}
	else
	{
		setImage(ImagesDirectory + mMutantImage);
	}
	this->SetLocation(xLocation, -450);


}



/**
* Destructor
*/
CMinion::~CMinion()
{
}

/**
*  Draw our minion
* \param graphics The graphics context to draw on
*/

void CMinion::Draw(Gdiplus::Graphics *graphics)
{

	CItem::Draw(graphics);

}



/**
 * Update position
 * \param elapsed elapsed time
 */
void CMinion::Update(double elapsed)
{
	CItem::Update(elapsed);

	CGetGruCoords visitor;
	mGame->Accept(&visitor);

	CVector gruLoc = visitor.GetCoords();
	CVector minionLoc = CVector(GetX(), GetY());

	CFlockingVisitor flocka = CFlockingVisitor(minionLoc, mV);
	mGame->Accept(&flocka);

	// Cohesion
	CVector cv;
	CVector cohesionCenter = flocka.Cohesion();
	cv = cohesionCenter - minionLoc;
	double l = cv.Length();
	if (l > 0)
	{
		cv /= l;
	}
	
	// Separation
	CVector sv = minionLoc - flocka.Closest();
	sv.Normalize();

	// Alignment
	CVector av = flocka.AlignmentAvg();
	if (av.Length() > 0)
	{
		av.Normalize();
	}

	// Attraction
	CVector gruV = gruLoc - minionLoc;
	if (gruV.Length() > 0)
	{
		gruV.Normalize();
	}

	if (!visitor.Exists())
	{
		gruV = CVector(0, 0);
	}

	mV = cv * 1 + sv * 3 + av * 5 + gruV * 10;
	mV.Normalize();

	mV *= MinionSpeed;
	CVector newP = minionLoc + mV * elapsed;

	//if (newP.X())
	SetLocation(newP.X(), newP.Y());
	/*
	//gruLoc *= -1;
	//CVector travelVector = gruLoc + minionLoc;
	//travelVector = travelVector.Normalize();

	mSpeedY = (travelVector.Y()) * -mMinionSpeed;
	mSpeedX = (travelVector.X()) * -mMinionSpeed;

	// when the Minion is running...
	// mSpeedX is a constant pixels per second running speed...
	mRunX = mSpeedX * elapsed;
	mRunY = mSpeedY * elapsed;

	this->SetLocation(GetX() + mRunX, GetY() + mRunY);
	*/
}