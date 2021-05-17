
// Task4View.h : interface of the CTask4View class
//

#pragma once


class CTask4View : public CView
{
protected: // create from serialization only
	CTask4View() noexcept;
	DECLARE_DYNCREATE(CTask4View)

// Attributes
public:
	CMap4Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	void DrawNode(CString& s, int x, int y, CDC* pDC);
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CTask4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Task4View.cpp
inline CMap4Doc* CTask4View::GetDocument() const
   { return reinterpret_cast<CMap4Doc*>(m_pDocument); }
#endif

