/**
* \file ChildView.cpp
*
* \author Alex Wuillaume
* ChildView.cpp : implementation of the CChildView class
*/



#include "stdafx.h"
#include "Mel.h"
#include "ChildView.h"
#include "DoubleBufferDC.h"
#include "NewGame.h"
#include "Minion.h"
#include "Gru.h"
#include "Villain.h"
#include "AryaStark.h"
#include "Blender.h"
#include "PokeBall.h"
#include "Timer.h"
#include "Scoreboard.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/// Frame duration in milliseconds
const int FrameDuration = 30;


/// Dimensions of the game play area
const int PlayAreaDimension = 500;




using namespace Gdiplus;
using namespace std;

// CChildView


CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
END_MESSAGE_MAP()





/**
* CChildView message handlers
* \param cs
* \returns
*/
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), NULL);
	return TRUE;
}


/**
* OnPaint
* BE CAREFUL ABOUT ADDING CODE HERE, this block gets called every fraction of a second and
* needs to be fast!
*/
void CChildView::OnPaint()
{
	CPaintDC paintDC(this);
	CDoubleBufferDC dc(&paintDC); // device context for painting
	Gdiplus::Graphics graphics(dc.m_hDC);

	CRect rect;
	GetClientRect(&rect);

	mGame.OnDraw(&graphics, rect.Width(), rect.Height());
	if (mFirstDraw || mGame.GetResetGameStatus())
	{

		mFirstDraw = false;
		mGame.SetResetGameStatus(false);
		SetTimer(1, FrameDuration, nullptr);

		auto newTimer = make_shared<CTimer>(&mGame);
		mGame.Add(newTimer);

		
		

		auto newgame = make_shared<CNewGame>(&mGame);
		newgame->SetLocation(-650, -500);
		mGame.Add(newgame);

		auto gru = make_shared<CGru>(&mGame);
		mGame.Add(gru);

		auto pokeBall = make_shared<CPokeBall>(&mGame);
		pokeBall->SetLocation(350.0, -250.0);
		mGame.Add(pokeBall);

		auto arya = make_shared<CAryaStark>(&mGame);
		arya->SetLocation(0.0, 300.0);
		mGame.Add(arya);

		auto blender = make_shared<CBlender>(&mGame);
		blender->SetLocation(-350.0, -250.0);
		mGame.Add(blender);

		auto scorePokeBall = make_shared<CPokeBall>(&mGame);
		scorePokeBall->SetLocation(750.0, 100.0);
		mGame.Add(scorePokeBall);

		auto scoreArya = make_shared<CAryaStark>(&mGame);
		scoreArya->SetLocation(750.0, -300.0);
		mGame.Add(scoreArya);

		auto scoreBlender = make_shared<CBlender>(&mGame);
		scoreBlender->SetLocation(750.0, -100.0);
		mGame.Add(scoreBlender);


		/*
		* Initialize the elapsed time system
		*/
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	}

	/*
	* Compute the elapsed time since the last draw
	*/
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	mGame.Update(elapsed);


}



/**
* Erase the background
*
* This is disabled to eliminate flicker
* \param pDC Device context
* \returns FALSE
*/
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;
}



/**
* Called when there is a left mouse button press
* \param nFlags Flags associated with the mouse button press
* \param point Where the button was pressed
*/
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{

	mGrabbedItem = mGame.HitTest(point.x, point.y);
	if (mGrabbedItem != nullptr && mGrabbedItem->IsMovable() != true)
	{
		if (mGrabbedItem->IsNewGame())
		{
			mGame.ResetGame();
		}
		mGrabbedItem = nullptr;

		

	}
}

/**
* Called when the left mouse buttis released
* \param nFlags Flags associated with the mouse button release
* \param point Where the button was pressed
*/
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{

	OnMouseMove(nFlags, point);

}

/**
* Called when the mouse is moved
* \param nFlags Flags associated with the mouse movement
* \param point Where the button was pressed
*/
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{


	// See if an item is currently being moved by the mouse
	if (mGrabbedItem != nullptr)
	{

		// Varibles for the virtual location of the grabbed item
		int virtualX = mGame.GetVirtualX(point.x);
		int virtualY = mGame.GetVirtualY(point.y);


		// If an item is being moved, we only continue to 
		// move it while the left button is down.
		if (nFlags & MK_LBUTTON)
		{

			mGrabbedItem->SetLocation(virtualX, virtualY);

		}
		else
		{
			// When the left button is released, we release the
			// item.
			mGrabbedItem = nullptr;
		}

		// Force the screen to redraw
		Invalidate();
	}
}

void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	Invalidate();
	CWnd::OnTimer(nIDEvent);
}
