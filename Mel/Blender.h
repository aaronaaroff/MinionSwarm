/**
* \file Blender.h
*
* \author Parker Dodson
*
* Class that implements Blender Villain
*/

#pragma once
#include <memory>
#include "Item.h"
#include "Villain.h"


/**
* Implements a Blender Villain
*/
class CBlender : public CVillain
{

private:
	std::unique_ptr<Gdiplus::Bitmap> mBlenderImage;


public:
	CBlender(CGame *game);

	/// Default constructor (disabled)
	CBlender() = delete;

	/// Copy constructor (disabled)
	CBlender(const CBlender &) = delete;

	virtual  ~CBlender();



};
