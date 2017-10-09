/**
* \file PokeBall.h
*
* \author Parker Dodson
*
* Class that implements Poke Ball Villain
*/

#pragma once
#include <memory>
#include "Item.h"
#include "Villain.h"


/**
* Implements a Poke Ball Villain
*/
class CPokeBall : public CVillain
{

private:
	std::unique_ptr<Gdiplus::Bitmap> mPokeBallImage;


public:
	CPokeBall(CGame *game);

	/// Default constructor (disabled)
	CPokeBall() = delete;

	/// Copy constructor (disabled)
	CPokeBall(const CPokeBall &) = delete;

	virtual  ~CPokeBall();



};
