/**
* \file DeleteItem.h
*
* \author Aaron Eshleman
*
*  Visitor class
*  Doesn't actually delete items, instead return a list of minions to sort through to kill
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

	std::vector<CMinion*> mMinions; ///<Minions to return


	/** Visit a CMinion object
	* \param minion Minion we are visiting */
	void CDeleteItem::VisitMinion(CMinion *minion)
	{
		mMinions.push_back(minion);
	}

	/** gets minions
	\return the minions*/
	std::vector<CMinion*> CDeleteItem::getMinions() { return mMinions; }
};

