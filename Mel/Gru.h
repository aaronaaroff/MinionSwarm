/**
* \file Gru.h
*
* \author Jon Stover
*
* Class that handles Gru and his properties
*/




#pragma once
#include "Item.h"

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

};

