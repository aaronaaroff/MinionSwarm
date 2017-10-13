/**
 * \file NewGame.cpp
 *
 * \author Aaron Eshleman
 */

#include "stdafx.h"
#include <string>
#include "NewGame.h"

using namespace Gdiplus;
using namespace std;

/// Button filename  
const wstring NewGameImage = L"images/new-game.png";

CNewGame::CNewGame(CGame *game) :
	CItem(game, NewGameImage)
{

}


///Not sure if hit test should be part of item or not, I think it should be
CNewGame::~CNewGame()
{
}

