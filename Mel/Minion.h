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
#include "Vector.h"

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


	/**  Draw this item
	* \param graphics The graphics context to draw on */
	virtual void Draw(Gdiplus::Graphics *graphics) override;

	void CMinion::Update(double elapsed);

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitMinion(this); }

	enum States { Jerry, Stuart, Mutant };

	/** Gets Minion Point Value */
	int getPoints() { return mPoints; }

	/** Gets Minion Touch Status */
	bool getTouched() { return mTouched; }

	/** Get velocity vector */
	CVector getV() { return mV; }

	/**
	* Function that returns whether or not item can be moved
	* \returns bool
	*/
	bool InZone()
	{
		return true;
	}

private:

	States mState = Jerry; ///<state of the minion

	/// Default image, may change in constructor
	std::wstring mMinionJerryImage = L"jerry.png";

	/// Default image, may change in constructor
	std::wstring mMinionStuartImage = L"stuart.png";

	/// Default image, may change in constructor
	std::wstring mMutantImage = L"mutant.png";

	/// Number of points that a minion is worth
	int mPoints = 0;

	/// Velocity vector
	CVector mV;

	/// Speed that the minion will be traveling at
	double mMinionSpeed = 0;

	/// Distance that the minion has run in X direction
	double mRunX = 0;

	// Distance that the minion has run in the y direction
	double mRunY = 0;

	///If the Minion has been touched by a villain or not
	bool mTouched = false;

	CVector mGruCoords; ///< current coords of gru

};

