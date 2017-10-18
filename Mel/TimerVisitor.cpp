#include "stdafx.h"
#include "Timer.h"
#include "TimerVisitor.h"


CTimerVisitor::CTimerVisitor()
{
}


CTimerVisitor::~CTimerVisitor()
{
}

void CTimerVisitor::VisitTimer(CTimer * timer)
{
	(*timer).setActive(false);
}
