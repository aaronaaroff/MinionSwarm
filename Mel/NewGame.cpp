#include "stdafx.h"
#include <string>
#include "NewGame.h"

using namespace Gdiplus;
using namespace std;

/// Button filename  \return none
const wstring FishGoldeenImageName(L"images/new-game.png");

/** 
* Constructor
* \param game the game we are using
*/

CNewGame::CNewGame(CGame *game)
{

}

CNewGame::~CNewGame()
{
}

///Not sure if hit test should be part of item or not, I think it should be