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

	bool IsMovable()
	{
		return true;
	}

private:

};

