/**
* \file DeleteMinion.h
*
* \author Aaron Eshleman
*
*  Class that implements a item visitor class.
*/


#pragma once
#include "ItemVisitor.h"
#include "Game.h"

class CDeleteMinion :
	public CItemVisitor
{
public:
	CDeleteMinion();
	virtual ~CDeleteMinion();

	/** Visit a CMinion object
	* \param minion Minion we are visiting */
	void CDeleteMinion::VisitMinion(CMinion *minion)
	{
		///minion->DeleteItem(minion);
		//Need to call a delete item function from minion that upcalls to Game
	}
};

