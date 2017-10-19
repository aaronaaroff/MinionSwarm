#include "stdafx.h"
#include "Minion.h"
#include "MinionVisitor.h"


CMinionVisitor::CMinionVisitor()
{
}


CMinionVisitor::~CMinionVisitor()
{
}

void CMinionVisitor::VisitMinion(CMinion * minion)
{
	int mMinionPoints = (*minion).getPoints();
}
