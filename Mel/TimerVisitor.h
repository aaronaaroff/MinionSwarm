#pragma once
#include "ItemVisitor.h"
class CTimerVisitor :
	public CItemVisitor
{
public:
	CTimerVisitor();
	virtual ~CTimerVisitor();

	void VisitTimer(CTimer * timer);
};

