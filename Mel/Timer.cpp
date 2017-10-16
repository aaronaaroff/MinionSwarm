/**
* \file Timer.cpp
*
* \author Jon Stover
*
* Class that handles Timer and his properties
*/



#include "stdafx.h"
#include <string>
#include "Timer.h"

using namespace Gdiplus;
using namespace std;

/// X-location of the timer
const int xLocation = 550; //1290

/// y-location of the timer
const int yLocation = -500; //25



const wstring TimerImage(L"images/gru.png");

CTimer::CTimer(CGame *game) :
	CItem(game, TimerImage)
{

	mStartTime = clock();
}

CTimer::~CTimer()
{
}


/**
* Load an image into a bitmap
* \param image Image pointer to load
* \param name Filename to load from
*/
void CTimer::LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name)
{
	wstring filename = name;
	image = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (image->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}



/// Draws timer in its box 
/// \param *graphics 
void CTimer::Draw(Gdiplus::Graphics *graphics)
{
	// Gets the elapsed time since start
	int elapsedTime = this->GetElpasedTime();

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


	//TODO: Do we need to draw a border around the timer?
	// Draws the border for the timer 
	//Pen pen(Color(0, 128, 0), 3);
	//graphics->DrawRectangle(&pen, xLocation, yLocation, 120, 50);

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

