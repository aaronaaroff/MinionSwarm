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

/// Cohesion weight
const double C_WEIGHT = 1;

/// Separation weight
const double S_WEIGHT = 3;

/// Alignment weight
const double A_WEIGHT = 5;

/// Attraction weight
const double G_WEIGHT = 10;

/// Mutant rate
const double M_WEIGHT = .85;

/// Normal Minion rate
const double NORM_WEIGHT = M_WEIGHT / 2;

/// Mutant points
const int MUTANT_POINT = 2;

/// Normal minion points
const int NORMAL_POINT = 1;

/** Constructor
* \param game The game this is a member of
*/
CMinion::CMinion(CGame *game) : CItem(game, ImagesDirectory + JerryMinion)
{
	double randomVariable = (double)rand() / RAND_MAX;
	if (randomVariable > M_WEIGHT)
	{
		mState = Mutant;
		mMinionSpeed = MutantSpeed;
		mPoints = MUTANT_POINT;

	}
	else if (randomVariable > NORM_WEIGHT)
	{
		mState = Stuart;
		mMinionSpeed = MinionSpeed;
		mPoints = NORMAL_POINT;
	}
	else
	{
		mState = Jerry;
		mMinionSpeed = MinionSpeed;
		mPoints = NORMAL_POINT;

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

	mV = cv * C_WEIGHT + sv * S_WEIGHT + av * A_WEIGHT + gruV * G_WEIGHT;
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