/**
* \file Item.h
*
* \author Aaron Eshleman
*
* Class that holds location information about each item in the game. (Gru, Minions, Villians)
*
* Circularly dependent on CGame
*
*/

#pragma once
#include <memory>
#include <string>

class CGame;

/**
* Data about items in game.
*/
class CItem
{
public:
	virtual ~CItem();

	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem &) = delete;

	/** The X location of the item
	* \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y);

	/// Draw this item
	/// \param graphics Graphics device to draw on
	virtual void Draw(Gdiplus::Graphics *graphics);

	/** Test this item to see if it has been clicked on
	* \param x X location on the game to test
	* \param y Y location on the game to test
	* \return true if clicked on */
	virtual bool HitTest(int x, int y);

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

	/// Get the game this item is in
	/// \returns Game pointer
	CGame *GetGame() { return mGame; }

	///Get the item image width for particular item
	double GetItemImageWidth() { return mItemImage->GetWidth(); }

	///Get the image height for particular item
	double GetItemImageHeight() { return mItemImage->GetHeight(); }


protected:
	///Constructs
	CItem(CGame *game);


private:
	/// The game this item is contained in
	CGame   *mGame;

	// Item location in the game
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item

	/// The image of this item.
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

};

