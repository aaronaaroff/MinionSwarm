/**
* \file Timer.h
*
* \author Tyler Gasper
*
* Class that will implement the game timer
*/


#pragma once


/**
 * Timer class
 */
class CTimer
{
public:
	CTimer();
	~CTimer();

	void CTimer::OnDraw(Gdiplus::Graphics * graphics);

private:

	long mStartTime; ///< Time that the game was started 

};

