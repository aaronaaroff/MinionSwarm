/**
* \file Villain.cpp
*
* \author Parker Dodson
*/

#include "stdafx.h"
#include <string>
#include "gdiplus.h"
#include "Villain.h"


using namespace Gdiplus;
using namespace std;


/// Arya Stark Villain filename 
const wstring AryaStarkImageName = L"images/arya.png";

/// Poke Ball Villain filename 
const wstring PokeBallImageName = L"images/pokeball.png";

/// Blender Villain filename 
const wstring BlenderImageName = L"images/juicer.png";

/// arya mult
const double ARYA_M = 1;

/// blend mult
const double BLENDER_M = 2;

/// poke mult
const double POKE_M = 3;

CVillain::~CVillain()
{
}

CVillain::CVillain(CGame * game, std::wstring name) :
	CItem( game, AryaStarkImageName)
{
	if (name == L"Arya")
	{
		mVillainType = AryaStark;
		mPointMultiplier = ARYA_M;
	}
	else if (name == L"Blender")
	{
		mVillainType = Blender;
		mPointMultiplier = BLENDER_M;
		setImage(BlenderImageName);
	}
	else
	{
		mVillainType = PokeBall;
		mPointMultiplier = POKE_M;
		setImage(PokeBallImageName);

	}
}


