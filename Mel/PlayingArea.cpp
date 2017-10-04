/**
 * \file PlayingArea.cpp
 *
 * \author Alex Wuillaume
 */

#include "stdafx.h"
#include "PlayingArea.h"
using namespace Gdiplus;

 /// The size of the playing area square in virtual pixels
const double GridSize = 1000.0f;

/// The range from the center to an edge for the playing area
/// in virtual pixels
const double GridRadius = GridSize / 2.0f;

/// Do not allow Minions or Gru to come closer than this distance
/// to the playing area edges (virtual pixels)
const double GridMargin = 50.0f;


/**
 * Constructor
 */
CPlayingArea::CPlayingArea()
{
}


/**
 * Destructor
 */
CPlayingArea::~CPlayingArea()
{
}

/**
 * Draws timer in its box
 * \param graphics screen to print on
 * \param width width of screen
 * \param height height of screen
 */
void CPlayingArea::OnDraw(Gdiplus::Graphics * graphics, int width, int height)
{
	// Draws the border for the timer
	Pen pen(Color(0, 128, 0), 1);

	int xcoords = -width / 2 + (width-GridSize)/2;
	int ycoords = -height / 2 + (height-GridSize)/2;
	graphics->DrawRectangle(&pen, xcoords, ycoords, GridSize,GridSize);
}
