/**
 * \file ItemVisitor.h
 *
 * \author Alex Wuillaume
 *
 * 
 */

#pragma once
#include "Vector.h"

class CGru;
class CVillain;
class CMinion;
class CNewGame;
class CTimer;

/**
 * Item Visitor class
 */
class CItemVisitor
{
public:
	CItemVisitor();
	virtual ~CItemVisitor();

	/** Visit a CMinion object
	* \param minion minion we are visiting */
	virtual void VisitMinion(CMinion *minion);

	/** Visit a CGru object
	* \param gru gru we are visiting */
	virtual void VisitGru(CGru *gru) {}

	/** Visit a CNewGame object
	* \param game CNewGame we are visiting */
	virtual void VisitNewGame(CNewGame *game) {}

	/** Visit a CVillain object
	* \param villain CVillain we are visiting */
	virtual void VisitVillain(CVillain *villain) {}

	/** Visit a CTimer object
	* \param villain CTimer we are visiting */
	virtual void VisitTimer(CTimer *timer) {}

private:
	int mNumTotalMinions = 0;
	int mNumMutant = 0;
	int mNumStuart = 0;
	int mNumJerry = 0;
};

