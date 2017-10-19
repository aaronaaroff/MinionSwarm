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
	/** Constructor
	* \param coords
	* \param v */
	CFlockingVisitor(CVector coords, CVector v) {mMinCoords = coords; mV = v;}

	/// remove destructor
	CFlockingVisitor() = delete;

	///destructor
	~CFlockingVisitor();

	/** Calculates cohesion vector
	* \return vector */
	CVector Cohesion();

	/** Calculates closest 
	* \return vector*/
	CVector Closest();

	/** Calculates alignment
	* \return vector */
	CVector AlignmentAvg();

	/** Visits
	* \param minion*/
	void VisitMinion(CMinion * minion);

private:
	/// Minion coords
	CVector mMinCoords;

	/// Minion velocity vector
	CVector mV;

	/// All game minions
	std::vector<CMinion*> mMinions;
};

