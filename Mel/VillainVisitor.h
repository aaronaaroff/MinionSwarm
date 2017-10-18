#pragma once
#include <vector>
#include "ItemVisitor.h"
#include "Game.h"

class CVillainVisitor :
	public CItemVisitor
{
public:
	CVillainVisitor();
	virtual ~CVillainVisitor();

	std::vector<CVillain*> mVillains;


	/** Visit a CMinion object
	* \param minion Minion we are visiting */
	void CVillainVisitor::VisitVillains(CVillain *villain)
	{
		mVillains.push_back(villain);
		///minion->DeleteItem(minion);
		//Need to call a delete item function from minion that upcalls to Game
	}

	std::vector<CVillain*> CVillainVisitor::getMinions() { return mVillains; }
};
