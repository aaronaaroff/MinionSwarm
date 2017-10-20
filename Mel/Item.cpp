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

/// Dimensions of the game play area
const int PlayAreaDimension = 500;


/**
 * Sets location of an item
 * \param x 
 * \param y 
 */
void CItem::SetLocation(double x, double y)
{

	
	if (this->InZone())
	{
		// Variables for the height and width of the grabbed item
		double imageWidth = this->GetItemImageWidth();
		double imageHeight = this->GetItemImageHeight();


		if (abs(x) + imageWidth / 2 >= PlayAreaDimension)
		{
			x = (PlayAreaDimension - imageWidth / 2) * (x / abs(x));
		}
		if (abs(y) + imageHeight / 2 >= PlayAreaDimension)
		{
			y = (PlayAreaDimension - imageHeight / 2) * (y / abs(y));
		}
	}


	mX = x;
	mY = y;
	
}


/**
 * Validates string, throws error message if image can't be opened
 * \param img 
 */
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
	setImage(filename);
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
bool CItem::HitTest(double x, double y)
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

