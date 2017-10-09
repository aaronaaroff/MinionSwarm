/**
* \file Minion.cpp
*
* \author Tyler Gasper


*/#include "stdafx.h"
#include "Minion.h"

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
CMinion::CMinion(CGame *game) : CItem(game, ImagesDirectory + MinionImage)
{

	/// Image to be used for the minion
	wstring MinionImage;

	double randomVariable = (double)rand() / RAND_MAX;
	if (randomVariable > .85)
	{
		MinionImage = MutantMinion;
		mSpeedX = MutantSpeed;
		mSpeedY = MutantSpeed;
		mPoints = 2;

	}
	else if (randomVariable > .5)
	{
		MinionImage = StuartMinion;
		mSpeedX = MinionSpeed;
		mSpeedY = MinionSpeed;
		mPoints = 1;
	}
	else
	{
		MinionImage = JerryMinion;
		mSpeedX = MinionSpeed;
		mSpeedY = MinionSpeed;
		mPoints = 1;

	}


	double xLocation = (500 - 77/2 )* (((double)rand() - (RAND_MAX/2))  / (RAND_MAX / 2));

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