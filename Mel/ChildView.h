
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
	CGame mGame; ///< The game class

	/// Any item we are currently dragging
	std::shared_ptr<CItem> mGrabbedItem;

	///See if its the first draw
	bool mFirstDraw = true;

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs) override;

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

