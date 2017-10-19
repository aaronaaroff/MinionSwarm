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
	CVector ret = CVector(gru->GetX(), gru->GetY());
	mGruCoords = ret;
	mGru = gru;
	mExists = true;
}
