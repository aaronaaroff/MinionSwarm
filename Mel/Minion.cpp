/**
* \file Minion.cpp
*
* \author Tyler Gasper


*/#include "stdafx.h"
#include <math.h>
#include "Minion.h"
#include "Vector.h"
#include "GetGruCoords.h"
#include "Game.h"

using namespace std;
using namespace Gdiplus;


/// Image directory name 
const wstring ImagesDirectory = L"images/";

/// Image of the standard minion
const wstring JerryMinion = L"jerry.png";

/// Image of a minion with a banana
const wstring StuartMinion = L"stuart.png";

/// Image of the mutated minion
const wstring MutantMinion = L"mutant.png";





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
		mMinionImage = MutantMinion;
		mSpeedX = MutantSpeed;
		mSpeedY = MutantSpeed;
		mMinionSpeed = MutantSpeed;
		mPoints = 2;

	}
	else if (randomVariable > .5)
	{
		mMinionImage = StuartMinion;
		mSpeedX = MinionSpeed;
		mSpeedY = MinionSpeed;
		mMinionSpeed = MinionSpeed;
		mPoints = 1;
	}
	else
	{
		mMinionImage = JerryMinion;
		mSpeedX = MinionSpeed;
		mSpeedY = MinionSpeed;
		mMinionSpeed = MinionSpeed;
		mPoints = 1;

	}


	double xLocation = (500 - 77/2 )* (((double)rand() - (RAND_MAX/2))  / (RAND_MAX / 2));
	setImage(ImagesDirectory + mMinionImage);
	this->SetLocation(xLocation, -450);


}



/**
* Destructor
*/
CMinion::~CMinion()
{
}



/**
* Load an image into a bitmap
* \param image Image pointer to load
* \param name Filename to load from
*/
void CMinion::LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name)
{
	wstring filename = ImagesDirectory + name;
	image = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (image->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}


/**
*  Draw our minion
* \param graphics The graphics context to draw on
*/
void CMinion::Draw(Gdiplus::Graphics *graphics)
{

	CItem::Draw(graphics);

	/*
	int wid = this->GetItemImageWidth();
	int hit = this->GetItemImageHeight();

	
	

	graphics->DrawImage(mStandardMinionImage.get(),
		(int)(GetX() + mRunX ), (int)(GetY() + mRunY),
		wid, hit);
		*/


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
	gruLoc *= -1;
	CVector minionLoc = CVector(GetX(), GetY());

	CVector travelVector = gruLoc + minionLoc;
	travelVector = travelVector.Normalize();

	mSpeedY = (travelVector.Y()) * -mMinionSpeed;
	mSpeedX = (travelVector.X()) * -mMinionSpeed;

	// when the Minion is running...
	// mSpeedX is a constant pixels per second running speed...
	mRunX = mSpeedX * elapsed;
	mRunY = mSpeedY * elapsed;

	this->SetLocation(GetX() + mRunX, GetY() + mRunY);
}