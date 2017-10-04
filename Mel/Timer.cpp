/**
* \file Timer.cpp
*
* \author Tyler Gasper
*/


#include "stdafx.h"
#include "Timer.h"
#include <string>

using namespace Gdiplus;
using namespace std;


/// X-location of the timer
const int xLocation = 0; //1290

/// y-location of the timer
const int yLocation = 0; //25


/**
* Constructor
*/
CTimer::CTimer()
{

	mStartTime = clock();

}

/**
* Destrcutor
*/
CTimer::~CTimer()
{
}



/// Draws timer in its box 
/// \param *graphics 
void CTimer::OnDraw(Gdiplus::Graphics *graphics)
{
	// Gets the elapsed time since start
	long currentTime = clock();
	int elapsedTime = (currentTime - mStartTime) / 1000;

	// Calculate the number of minutes/seconds elapsed
	string minutes = to_string(elapsedTime / 60);
	string seconds = to_string(elapsedTime % 60);

	// Pads the minutes and seconds out to 2 characters 
	minutes = string(2 - minutes.length(), '0') + minutes;
	seconds = string(2 - seconds.length(), '0') + seconds;

	// Builds the strin for the time display
	string tempTime = minutes + ":" + seconds;

	// Converts the basic string to a string for the gdi class 
	wstring time(tempTime.begin(), tempTime.end());
	const wchar_t* s = time.c_str();


	// Draws the border for the timer
	Pen pen(Color(0, 128, 0), 3);
	graphics->DrawRectangle(&pen, xLocation, yLocation, 120, 50);

	// bit that will fill in the bakc of the timer
	// SolidBrush brush(Color(0, 0, 0));
	// graphics->FillRectangle(&brush, xLocation, yLocation, 120, 50);

	// Set the font attributes
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 32);

	// Draws the time in the timer rectangle
	SolidBrush green(Color(0, 128, 0));
	graphics->DrawString(s,  // String to draw
		-1,         // String length, -1 means it figures it out on its own
		&font,      // The font to use
		PointF(xLocation, yLocation),   // Where to draw (top left corner)
		&green);    // The brush to draw the text with



}
