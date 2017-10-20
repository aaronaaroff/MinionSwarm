/**
 * \file ChildView.h
 *
 * \author Alex Wuillaume
 *
 * 
 */

#pragma once
#include "Game.h"

/**
 * Childview class
 */
class CChildView : public CWnd
{
// Construction
public:
	CChildView();
private:
	CGame *mGame; ///< The game class

	/// True until the first time we draw
	bool mFirstDraw = true;

	long long mLastTime;    ///< Last time we read the timer
	double mTimeFreq;       ///< Rate the timer updates

	/// Any item we are currently dragging
	std::shared_ptr<CItem> mGrabbedItem;

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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
 };

