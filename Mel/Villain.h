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


	/** accept override
	* \param visitor*/
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitVillain(this); }

	/** Gets points
	* \return points*/
	int GetPoints() { return mPoints; }
	
	/** Gets multiplier
	* \return multiplier */
	int getMultiplier() { return mPointMultiplier; }

	///States that the Villain Object can be in.
	enum VillainStates { AryaStark, Blender, PokeBall };

	/**
	* Constructor
	* \param game The Game we are in
	* \param filename Filename for the image we use
	* \param pointMultiplier the multiplier
	*/
	CVillain(CGame *game,  const std::wstring name);
	



	

private:

	///Villain Image
	std::unique_ptr<Gdiplus::Bitmap> mVillainImage;

	///Villain Point Multiplier
	int mPointMultiplier;

	///Points on the villain
	int mPoints = 0;

	///Villain State 
	VillainStates mVillainType; 




};



