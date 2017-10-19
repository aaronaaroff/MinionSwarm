/**
 * \file GetGruCoords.cpp
 *
 * \author Alex Wuillaume
 *
 * Gets gru, allows for fetching his coords
 */

#include "stdafx.h"
#include "GetGruCoords.h"
#include "Gru.h"

CGetGruCoords::CGetGruCoords()
{
}


CGetGruCoords::~CGetGruCoords()
{
}

void CGetGruCoords::VisitGru(CGru * gru)
{
	mGru = gru;
	mExists = true;
}
