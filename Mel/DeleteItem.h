/**
* \file DeleteMinion.h
*
* \author Aaron Eshleman
*
*  Class that implements a item visitor class.
*/


#pragma once
#include <vector>
#include "ItemVisitor.h"
#include "Game.h"


/**
 * Visitor to generate list of minions
 */
class CDeleteItem :
	public CItemVisitor
{
public:
	CDeleteItem();
	virtual ~CDeleteItem();

	std::vector<CMinion*> mMinions;


	/** Visit a CMinion object
	* \param minion Minion we are visiting */
	void CDeleteItem::VisitMinion(CMinion *minion)
	{
		mMinions.push_back(minion);
		///minion->DeleteItem(minion);
		//Need to call a delete item function from minion that upcalls to Game
	}

	std::vector<CMinion*> CDeleteItem::getMinions() { return mMinions; }
};

