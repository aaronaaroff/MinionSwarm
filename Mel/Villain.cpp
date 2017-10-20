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





CVillain::~CVillain()
{
}

CVillain::CVillain(CGame * game, std::wstring name) :
	CItem( game, AryaStarkImageName)
{
	if (name == L"Arya")
	{
		mVillainType = AryaStark;
		mPointMultiplier = 1;
	}
	else if (name == L"Blender")
	{
		mVillainType = Blender;
		mPointMultiplier = 2;
		setImage(BlenderImageName);
	}
	else
	{
		mVillainType = PokeBall;
		mPointMultiplier = 3;
		setImage(PokeBallImageName);

	}
}


