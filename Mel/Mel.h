// Mel.h : main header file for the Mel application


//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


/**
 * Creates our game
 */
class CMelApp : public CWinApp
{

private:
	Gdiplus::GdiplusStartupInput gdiplusStartupInput; ///< Starts up
	ULONG_PTR gdiplusToken;								///< Token for gdi					

public:
	CMelApp(); ///< Application


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMelApp theApp;
