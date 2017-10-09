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

	mGame.OnDraw(&graphics, rect.Width(), rect.Height());

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