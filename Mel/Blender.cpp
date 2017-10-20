/**
* \file Blender.cpp
*
* \author Parker Dodoson
*/

#include "stdafx.h"

#include <string>

#include "gdiplus.h"
#include "Blender.h"


using namespace Gdiplus;
using namespace std;



/// Villain Point Multiplier
const int pointMultiplier = 2;


/** Constructor
* \param game The game this is a member of
*/
CBlender::CBlender(CGame *game) :
	CVillain(game, BlenderImageName, pointMultiplier)
{
}

/**
* Destructor
*/
CBlender::~CBlender()
{
}


