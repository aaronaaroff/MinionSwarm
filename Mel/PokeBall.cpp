/**
* \file PokeBall.cpp
*
* \author Parker Dodoson
*/

#include "stdafx.h"

#include <string>

#include "gdiplus.h"
#include "PokeBall.h"


using namespace Gdiplus;
using namespace std;


/// Villain Point Multiplier
const int pointMultiplier = 3;







/** Constructor
* \param game The game this is a member of
*/
CPokeBall::CPokeBall(CGame *game) :
	CVillain(game, PokeBallImageName, pointMultiplier)
{
}

/**
* Destructor
*/
CPokeBall::~CPokeBall()
{
}

