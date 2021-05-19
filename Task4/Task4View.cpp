
// Task4View.cpp : implementation of the CTask4View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Task4.h"
#include "CountPrinter.h"
#endif
#include <iostream>
#include <fstream>
#include "Task4Doc.h"
#include "Task4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTask4View

IMPLEMENT_DYNCREATE(CTask4View, CScrollView)

BEGIN_MESSAGE_MAP(CTask4View, CScrollView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
 

	ON_COMMAND(ID_BUTTON_ADD_WORDS, &CTask4View::OnButtonAddWords)
	ON_COMMAND(ID_BUTTON_ALPHA_SORT, &CTask4View::OnButtonAlphaSort)
	ON_COMMAND(ID_BUTTON_COUNT_SORT, &CTask4View::OnButtonCountSort)
END_MESSAGE_MAP()

// CTask4View construction/destruction

CTask4View::CTask4View() noexcept
{

	// TODO: add construction code here

}

CTask4View::~CTask4View()
{
}
void CTask4View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	//Определить размер документа
	CSize DocSize(20000, 20000);
	//Установить режим отображения и размер документа
	SetScrollSizes(MM_TEXT, DocSize, CSize(500, 500), CSize(50, 50));
}

BOOL CTask4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTask4View drawing

void CTask4View::OnDraw(CDC* pDC)
{
	CMap4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//pDC->Rectangle(0, 0, 500, 500);
	std::string str = GetDocument()->GetMap()->print(basePrinter);
	CRect rcText(0, 0, 500, 20000);
	pDC->DrawText(CString(CA2T(str.c_str())), &rcText, DT_LEFT);

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
void CTask4View::OnButtonAddWords()
{
	///CFileDialog fileDialog(true, NULL, "*.*", OFN_ALLOWMULTISELECT);
  CFileDialog fileDialog(TRUE, _T("*.*"), NULL,OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT, _T("All files and folders(*.*)|*.*||"));  
	int result = fileDialog.DoModal();
	if (result == IDOK)
	{
	 	POSITION ps = fileDialog.GetStartPosition();		 
		string resStr = "";
		std::string line;
		std::ifstream in(fileDialog.GetNextPathName(ps));
		if (in.is_open())
		{
			while (getline(in, line))
			{
				resStr += line;
				resStr += " ";
			}
			GetDocument()->GetMap()->addWords(resStr);
		}
		in.close();
		Invalidate();
		UpdateWindow();
	 }
	 
	//getDocument
	// TODO: добавьте свой код обработчика команд
}


void CTask4View::OnButtonAlphaSort()
{
	basePrinter = new BasePrinter();
	Invalidate();
	UpdateWindow();
	// TODO: добавьте свой код обработчика команд
}


void CTask4View::OnButtonCountSort()
{
	basePrinter = new CountPrinter();
	Invalidate();
	UpdateWindow();
	// TODO: добавьте свой код обработчика команд
}
