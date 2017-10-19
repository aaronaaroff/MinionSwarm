/**
* \file MinionVisitor.h
*
* \author Alex Wuillaume
*
*
*/

#pragma once
#include <vector>
#include <memory>
#include "Minion.h"
#include "ItemVisitor.h"
#include "Vector.h"

/**
* Visits minion to get flocking information
*/
class CFlockingVisitor : public CItemVisitor
{
public:
	CFlockingVisitor(CVector coords, CVector v) {mMinCoords = coords; mV = v;}
	CFlockingVisitor() = delete;
	~CFlockingVisitor();

	CVector Cohesion();

	CVector Closest();

	CVector AlignmentAvg();

	void VisitMinion(CMinion * minion);

private:
	/// Minion coords
	CVector mMinCoords;

	/// Minion velocity vector
	CVector mV;

	/// All game minions
	std::vector<CMinion*> mMinions;
};

