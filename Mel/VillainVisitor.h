/**
 * \file VillainVisitor.h
 *
 * \author Alex Wuillaume
 *
 * 
 */

#pragma once
#include <vector>
#include "ItemVisitor.h"
#include "Game.h"


/**
 * Visits all of the villains
 */
class CVillainVisitor :
	public CItemVisitor
{
public:
	///constructor
	CVillainVisitor();

	///destructor
	virtual ~CVillainVisitor();

	/// villains
	std::vector<CVillain*> mVillains;


	/** Visit a CVillain object
	* \param villain villain we are visiting */
	void CVillainVisitor::VisitVillain(CVillain *villain)
	{
		mVillains.push_back(villain);
		///minion->DeleteItem(minion);
		//Need to call a delete item function from minion that upcalls to Game
	}

	/** Gets minions
	* \return villains */
	std::vector<CVillain*> CVillainVisitor::getMinions() { return mVillains; }
};
