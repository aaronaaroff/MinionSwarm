/**
* \file Gru.cpp
*
* \author Jon Stover
*
* Class that handles Gru and his properties
*/



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


/**
* Load an image into a bitmap
* \param image Image pointer to load
* \param name Filename to load from
*/
void CGru::LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name)
{
	wstring filename = name;
	image = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (image->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

