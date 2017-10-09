/**
* \file Minion.h
*
* \author Tyler Gasper
*
* Class that handles the moving, creation,
* and changing of minions as we interact with them
*
* Class that will handle the new minions
* in the city
*/

#pragma once

#include "Item.h"

/**
* Class that will handle the new minions
*/
class CMinion : public CItem
{
public:

	CMinion(CGame *game);

	///  Default constructor (disabled)
	CMinion() = delete;

	///  Copy constructor (disabled)
	CMinion(const CMinion &) = delete;

	~CMinion();


	/**
	* Load an image into a bitmap
	* \param image Image pointer to load
	* \param name Filename to load from
	*/
	void CMinion::LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name);

	/**  Draw this item
	* \param graphics The graphics context to draw on */
	virtual void Draw(Gdiplus::Graphics *graphics) override;


	/**
	* Called before the image is drawn
	* \param elapsed Time since last draw
	*/
	void CMinion::Update(double elapsed)
	{
		CItem::Update(elapsed);
		// when the Minion is running...
		// mSpeedX is a constant pixels per second running speed...
		mRunX = mSpeedX * elapsed;
		mRunY = mSpeedY * elapsed;


		this->SetLocation(GetX() + mRunX,GetY() + mRunY);
	}

private:

	/// Number of points that a minion is worth
	int mPoints = 0;

	/// Speed that the minion will be traveling at
	double mSpeedX = 0;

	double mSpeedY = 0;


	/// Distance that the minion has run in X direction
	double mRunX = 0;


	// Distance that the minion has run in the y direction
	double mRunY = 0;



};

