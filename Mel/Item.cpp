/**
* \file Item.cpp
*
* \author Aaron Eshleman
*/

#include "stdafx.h"
#include "Item.h"
#include "Game.h"
#include <string>

using namespace Gdiplus;
using namespace std;



void CItem::SetLocation(double x, double y)
{
	mX = x;
	mY = y;
}

void CItem::setImage(std::wstring img)
{
	mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(img.c_str()));
	if (mItemImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += img;
		AfxMessageBox(msg.c_str());
	}
}

/** Constructor
* \param game The game this item is a member of
*/
CItem::CItem(CGame *game, const std::wstring &filename) : mGame(game)
{
	mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (mItemImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}


/**
* Destructor
*/
CItem::~CItem()
{
}

/**
*  Test to see if a coordinate postion is within a certain item image.
* \param x X position to test
* \param y Y position to test
* \return true if hit.
*/
bool CItem::HitTest(int x, int y)
{
	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();

	// Make x and y relative to the top-left corner of the bitmap image.
	// Subtracting the center makes x, y relative to the center of 
	// the image. Adding half the size makes x, y relative to the top 
	// corner of the image.
	double testX = x - GetX() + wid / 2;
	double testY = y - GetY() + hit / 2;

	// Test to see if x, y are in the image
	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
	{
		// We are outside the image
		return false;
	}

	// Test to see if x, y are in the drawn part of the image
	auto format = mItemImage->GetPixelFormat();
	if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
	{
		// This image has an alpha map, which implements the 
		// transparency. If so, we should check to see if we
		// clicked on a pixel where alpha is not zero, meaning
		// the pixel shows on the screen.
		Color color;
		mItemImage->GetPixel((int)testX, (int)testY, &color);
		return color.GetAlpha() != 0;
	}
	else {
		return true;
	}
}

/**
* Draw this item
* \param graphics Graphics device to draw on
*/
void CItem::Draw(Gdiplus::Graphics *graphics)
{
	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();

	graphics->DrawImage(mItemImage.get(),
		float(GetX() - wid / 2), float(GetY() - hit / 2),
		(float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
	
}

