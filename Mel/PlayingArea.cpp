/**
 * \file PlayingArea.cpp
 *
 * \author Alex Wuillaume
 */

#include "stdafx.h"
#include "PlayingArea.h"

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
