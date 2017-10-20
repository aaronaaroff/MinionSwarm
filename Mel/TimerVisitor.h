/**
 * \file TimerVisitor.h
 *
 * \author Alex Wuillaume
 *
 * 
 */

#pragma once
#include "ItemVisitor.h"


/**
 * Visitor
 */
class CTimerVisitor :
	public CItemVisitor
{
public:
	///Constructor
	CTimerVisitor();

	///Destructor
	virtual ~CTimerVisitor();

	/** Gets virtual x
	* \param timer */
	void VisitTimer(CTimer * timer);
};

