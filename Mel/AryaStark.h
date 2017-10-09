
/**
* \file AryaStark.h
*
* \author Parker Dodson
*
* Class that implements AryaStark Villain
*/

#pragma once
#include <memory>
#include "Item.h"
#include "Villain.h"


/**
* Implements an AryaStark Villain
*/
class CAryaStark : public CVillain
{

private:
	std::unique_ptr<Gdiplus::Bitmap> mAryaStarkImage;


public:
	CAryaStark(CGame *game);

	/// Default constructor (disabled)
	CAryaStark() = delete;

	/// Copy constructor (disabled)
	CAryaStark(const CAryaStark &) = delete;

	virtual  ~CAryaStark();



};