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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
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
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);
	return TRUE;
}


/**
 * OnPaint
 */
void CChildView::OnPaint() 
{
	CPaintDC paintDC(this);
	CDoubleBufferDC dc(&paintDC); // device context for painting
	Graphics graphics(dc.m_hDC);

	CRect rect;
	GetClientRect(&rect);

	auto newgame = make_shared<CNewGame>(&mGame);
	newgame->SetLocation(-650, -500);
	mGame.Add(newgame);
	if (mFirstDraw)
	{
		mFirstDraw = false;
		auto gru = make_shared<CGru>(&mGame);
		mGame.Add(gru);
	}

	mGame.Update(.033333);

	mGame.OnDraw(&graphics, rect.Width(), rect.Height());


	auto newMinion = make_shared<CMinion>(&mGame);
	mGame.Add(newMinion);

	Invalidate();
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

}

/**
* Called when the left mouse button is released
* \param nFlags Flags associated with the mouse button release
* \param point Where the button was pressed
*/
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	OnMouseMove(nFlags, point);

}


/**
* Called when the mouse is moved
* \param nFlags Flags associated with the mouse movement
* \param point Where the button was pressed
*/
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// See if an item is currently being moved by the mouse
	if (mGrabbedItem != nullptr)
	{
		// If an item is being moved, we only continue to 
		// move it while the left button is down.
		if (nFlags & MK_LBUTTON)
		{
			mGrabbedItem->SetLocation(point.x, point.y);
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