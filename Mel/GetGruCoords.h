/**
* \file GetGruCoords.h
*
* \author Alex Wuillaume
*
*
*/

#pragma once
#include "ItemVisitor.h"
#include "Gru.h"
#include "Vector.h"

/**
* Retrieves coords of Gru
*/
class CGetGruCoords : public CItemVisitor
{
public:
	/** Constructor */
	CGetGruCoords();
	~CGetGruCoords();

	/** Visits gru
	* \param gru who we're visiting */
	void VisitGru(CGru * gru);

	/** Gets coords of gru
	* \return coords */
	CVector GetCoords() { 
		if (mExists)
			return CVector(mGru->GetX(), mGru->GetY());
		return CVector(0, 0);
	}

	/** Gets status of gru
	* \return exists */
	bool Exists() { return mExists; }

	/** Gets coords of gru
	* \return pointer to gru */
	CGru * GetGru() { return mGru; }

private:
	/// Pointer to gru
	CGru *mGru;

	/// If exists must be changed to true
	bool mExists = false;
};
