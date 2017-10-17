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

	void CMinion::Update(double elapsed);

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitMinion(this); }

private:
	/// Default image, may change in constructor
	std::wstring mMinionImage = L"jerry.png";

	/// Number of points that a minion is worth
	int mPoints = 0;

	/// Speed that the minion will be traveling at
	double mSpeedX = 0;

	double mSpeedY = 0;

	double mMinionSpeed = 0;

	/// Distance that the minion has run in X direction
	double mRunX = 0;


	// Distance that the minion has run in the y direction
	double mRunY = 0;

	///If the Minion has been touched by a villain or not
	bool touched = false;

	CVector mGruCoords;

};

