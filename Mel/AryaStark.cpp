/**
* \file AryaStark.cpp
*
* \author Parker Dodoson
*/

#include "stdafx.h"

#include <string>

#include "gdiplus.h"
#include "AryaStark.h"





/// Villain Point Multiplier
const int pointMultiplier = 1;







/** Constructor
* \param game The game this is a member of
*/
CAryaStark::CAryaStark(CGame *game) :
	CVillain(game, AryaStarkImageName, pointMultiplier)
{
}

/**
* Destructor
*/
CAryaStark::~CAryaStark()
{
}



