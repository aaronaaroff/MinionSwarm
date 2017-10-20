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

/** Gru img location
* \return wstring the string*/
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



/**
* Update position
* \param elapsed elapsed time
*/
void CGru::Update(double elapsed)
{
	
	/* will call the virtual pixel coordinates
	* to determine if gru is on a border. If he is either
	* keep setting his location to the border or
	* make mGrabbedItem = nullptr'
	*/
	//auto xLocation = this->GetVirtualX(this->GetX());
	//auto yLocation = this->GetVirtualY(this->GetY());
}