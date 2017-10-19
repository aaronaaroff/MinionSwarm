/**
* \file Gru.h
*
* \author Jon Stover
*
* Class that handles Gru and his properties
*/

#pragma once
#include "Item.h"
#include "ItemVisitor.h"

/**
 * Gru class
 */
class CGru :
	public CItem
{
public:

	CGru::CGru(CGame *game);
	virtual ~CGru();

	/// Default constructor (disabled)
	CGru() = delete;

	/// Copy constructor (disabled)
	CGru(const CGru &) = delete;

	/**
	* Load an image into a bitmap
	* \param image Image pointer to load
	* \param name Filename to load from
	*/
	void LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name);

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitGru(this); }


	/**
	* function that returns whether or not item can be moved
	* \returns bool
	*/
	bool IsMovable()
	{
		return true;
	}


	/**
	* Function that returns whether or not item can be moved
	* \returns bool
	*/
	bool InZone()
	{
		return true;
	}

	/**
	* Function that will keep gru in the gamespace and update if he is alive or not
	* \param elapsed elpased time since last update
	*/
	void CGru::Update(double elapsed);

private:
	///Bool to show if Gru is Alive or not
	bool mAlive = true;

};

