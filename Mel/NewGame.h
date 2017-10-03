#pragma once
#include "Item.h"
class CNewGame :
	public CItem
{
public:
	/**
	* Constructor for Goldeen Fish
	* \param *aquarium gives aquarium for fish
	*/
	CNewGame::CNewGame(CGame *game);
	virtual ~CNewGame();

	/// Default constructor (disabled)
	CNewGame() = delete;

	/// Copy constructor (disabled)
	CNewGame(const CNewGame &) = delete;
};

