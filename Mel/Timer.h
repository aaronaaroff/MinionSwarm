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

	CTimer::CTimer(CGame *game);
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
	*/
	int GetElpasedTime() 
	{
		return mElapsedTime;
	}

	/** 
	* Function that adds the elpased time from game 
	* to the timer to eliminate the use of a second
	* clock call
	* \param elapsed Elapsed time in ms
	*/
	void Update(double elapsed)
	{
		mElapsedTime += elapsed;
	}


	/**  Draw this item
	* \param graphics The graphics context to draw on */
	virtual void Draw(Gdiplus::Graphics *graphics) override;

private:

	long mStartTime; ///< Time that the game was started

	double mElapsedTime = 0; ///< Time that has elapsed since the start

};

