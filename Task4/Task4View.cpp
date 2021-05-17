
// Task4View.cpp : implementation of the CTask4View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Task4.h"
#endif

#include "Task4Doc.h"
#include "Task4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTask4View

IMPLEMENT_DYNCREATE(CTask4View, CView)

BEGIN_MESSAGE_MAP(CTask4View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTask4View construction/destruction

CTask4View::CTask4View() noexcept
{
	// TODO: add construction code here

}

CTask4View::~CTask4View()
{
}

BOOL CTask4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTask4View drawing

void CTask4View::OnDraw(CDC* /*pDC*/)
{
	CMap4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CTask4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTask4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTask4View diagnostics

#ifdef _DEBUG
void CTask4View::AssertValid() const
{
	CView::AssertValid();
}

void CTask4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMap4Doc* CTask4View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMap4Doc)));
	return (CMap4Doc*)m_pDocument;
}
#endif //_DEBUG


// CTask4View message handlers
