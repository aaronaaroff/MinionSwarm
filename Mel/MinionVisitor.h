#pragma once
#include "ItemVisitor.h"
class CMinionVisitor :
	public CItemVisitor
{
public:
	CMinionVisitor();
	virtual ~CMinionVisitor();

	void VisitMinion(CMinion* minion);

private:
	int mMinionPoints;
};

