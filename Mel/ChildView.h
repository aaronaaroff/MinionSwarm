
// ChildView.h : interface of the CChildView class
//


#pragma once

#include "Game.h"


// CChildView window


/**
 * Childview class
 */
class CChildView : public CWnd
{
// Construction
public:
	CChildView();
private:
	CGame mGame;

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

