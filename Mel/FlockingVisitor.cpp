/**
 * \file FlockingVisitor.cpp
 *
 * \author Alex Wuillaume
 */

#include "stdafx.h"
#include "FlockingVisitor.h"
#include <limits>

using namespace std;

/// Radius around minion to calculate alignment
const double AlignmentRadius = 200;

/**
 * Destructor
 */
CFlockingVisitor::~CFlockingVisitor()
{
}


CVector CFlockingVisitor::Cohesion()
{
	CVector coh;
	for (CMinion* x : mMinions)
	{
		coh += CVector(x->GetX(), x->GetY());
	}
	return coh / mMinions.size();
}

CVector CFlockingVisitor::Closest()
{
	double min = DBL_MAX;
	CVector minP;
	for (CMinion* x : mMinions)
	{
		if (mMinCoords.Distance(CVector(x->GetX(), x->GetY())) < min && mMinCoords.Distance(CVector(x->GetX(), x->GetY())) > 0)
		{
			min = mMinCoords.Distance(CVector(x->GetX(), x->GetY()));
			minP = CVector(x->GetX(), x->GetY());
		}
	}
	return minP;
}

CVector CFlockingVisitor::AlignmentAvg()
{
	CVector align;
	for (CMinion* x : mMinions)
	{
		if (mMinCoords.Distance(CVector(x->GetX(), x->GetY())) < AlignmentRadius)
		{
			align += x->getV();
		}
	}
	return align;
}

void CFlockingVisitor::VisitMinion(CMinion * minion)
{
	mMinions.push_back(minion);
}
