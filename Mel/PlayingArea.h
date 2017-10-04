/**
 * \file PlayingArea.h
 *
 * \author Alex Wuillaume
 *
 * 
 */

#pragma once


/**
 * Playing Area Class
 */
class CPlayingArea
{
public:
	CPlayingArea();
	~CPlayingArea();

	void OnDraw(Gdiplus::Graphics *graphics, int width, int height);
};

