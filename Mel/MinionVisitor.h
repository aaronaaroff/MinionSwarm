/**
 * \file MinionVisitor.h
 *
 * \author Alex Wuillaume
 *
 * 
 */

#pragma once
#include "ItemVisitor.h"


/**
 * Visits minion to get their points
 */
class CMinionVisitor :
	public CItemVisitor
{
public:
	CMinionVisitor();
	virtual ~CMinionVisitor();

	void VisitMinion(CMinion* minion);

private:
	int mMinionPoints; ///<point val of minion
};

