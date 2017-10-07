#include "stdafx.h"
#include <string>
#include "Gru.h"

using namespace Gdiplus;
using namespace std;

const wstring GruImage(L"images/gru.png");

CGru::CGru(CGame *game) : 
	CItem(game, GruImage)
{

}

CGru::~CGru()
{
}
