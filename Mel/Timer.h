/**
* \file Timer.h
*
* \author Jon Stover
*
* Class that handles Timer and his properties
*/

#pragma once
#include "Item.h"
#include "ItemVisitor.h"

/**
* Timer class
*/
class CTimer :
	public CItem
{
public:
	/** Constructor
	* \param game the game*/
	CTimer::CTimer(CGame *game);

	/** Destructor*/
	virtual ~CTimer();

	/// Default constructor (disabled)
	CTimer() = delete;

	/// Copy constructor (disabled)
	CTimer(const CTimer &) = delete;

	/**
	* Load an image into a bitmap
	* \param image Image pointer to load
	* \param name Filename to load from
	*/
	void LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name);

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitTimer(this); }

	/**
	* Function to get the elapsed time since start
	* \return the elapsed time
	*/
	double GetElpasedTime() 
	{
		return mElapsedTime;
	}

	/** 
	* Function that adds the elpased time from game 
	* to the timer to eliminate the use of a second
	* clock call
	* If clock is not active, no time is added to timer
	* \param elapsed Elapsed time in ms
	*/
	void Update(double elapsed)
	{
		if (mActive)
		{
			mElapsedTime += elapsed;
		}
		else
		{
			mElapsedTime += 0;
		}
	}


	/**  Draw this item
	* \param graphics The graphics context to draw on */
	virtual void Draw(Gdiplus::Graphics *graphics) override;

	/** Setter for mActive
	*\param isActive bool active to see if it is active or not */
	void setActive(bool isActive) { mActive = isActive; }

private:

	long mStartTime; ///< Time that the game was started

	double mElapsedTime = 0; ///< Time that has elapsed since the start

	/// to See if the Timer is Active or Not
	bool mActive = true;

};

