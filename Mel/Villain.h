/**
* \file Villain.h
*
* \author Parker Dodson
*
* Hosts the Generic Villain Class
*
*/

#pragma once
#include "Gdiplus.h"
#include "Game.h"
#include "Item.h"


#include <memory>



/**
* Base class for a Villain
* This applies to all of the Villains
* items in the game.
*/
class CVillain :
	public CItem
{
public:
	/// Default constructor (disabled)
	CVillain() = delete;

	/// Copy constructor (disabled)
	CVillain(const CVillain &) = delete;

	virtual ~CVillain();



protected:
	/**
	* Constructor
	* \param Game The Game we are in
	* \param filename Filename for the image we use
	*/
	CVillain::CVillain(CGame *game, const std::wstring &filename, int pointMultipler) :
		CItem(game, filename)
	{
		mVillainImage = std::unique_ptr<Gdiplus::Bitmap>(
			Gdiplus::Bitmap::FromFile(filename.c_str()));
		if (mVillainImage->GetLastStatus() != Gdiplus::Status::Ok)
		{
			AfxMessageBox(L"Failed to open image");
		}
		mPointMultiplier = pointMultipler;




	}



private:

	///Villain Image
	std::unique_ptr<Gdiplus::Bitmap> mVillainImage;

	///Villain Point Multiplier
	int mPointMultiplier;


};



