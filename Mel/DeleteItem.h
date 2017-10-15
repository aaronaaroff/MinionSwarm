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

class CDeleteItem :
	public CItemVisitor
{
public:
	CDeleteItem();
	virtual ~CDeleteItem();

	/** Visit a CMinion object
	* \param minion Minion we are visiting */
	void CDeleteItem::VisitMinion(CMinion *minion)
	{
		///minion->DeleteItem(minion);
		//Need to call a delete item function from minion that upcalls to Game
	}
};

