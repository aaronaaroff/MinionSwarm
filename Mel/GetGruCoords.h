/**
* \file GetGruCoords.h
*
* \author Alex Wuillaume
*
*
*/

#pragma once
#include "ItemVisitor.h"
#include "Vector.h"

/**
* Retrieves coords of Gru
*/
class CGetGruCoords : public CItemVisitor
{
public:
	CGetGruCoords();
	~CGetGruCoords();

	void VisitGru(CGru * gru);

	CVector GetCoords() const { return mGruCoords; }

	CGru * GetGru() { return mGru; }

	CGru *mGru;
private:
	CVector mGruCoords;
};
