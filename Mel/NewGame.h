/**
 * \file NewGame.h
 *
 * \author Jon Stover
 *
 * 
 */

#pragma once
#include "Item.h"
#include "ItemVisitor.h"


/**
 * NewGame button
 */
class CNewGame :
	public CItem
{
public:
	/**
	* Constructor for newgame button
	* \param *game
	*/
	CNewGame(CGame *game);

	virtual ~CNewGame();

	/// Default constructor (disabled)
	CNewGame() = delete;

	/// Copy constructor (disabled)
	CNewGame(const CNewGame &) = delete;

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor*visitor) override { visitor->VisitNewGame(this); }

	/**
	* Function that returns whether or not item can be moved
	* \returns bool
	*/
	virtual bool IsNewGame()
	{
		return true;
	}
};

