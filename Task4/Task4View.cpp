
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
	//GetDocument()->GetMap()->addWords("exe' (Win32): Loaded 'C:\Windows\SysWOW64\WinTypes.dll'. 'Task4.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\WinTypes.dll'.		'Task4.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\ntmarta.dll'.		'Task4.exe' (Win32) : Unloaded 'C:\Windows\SysWOW64\WinTypes.dll'		'Task4.exe' (Win32) : Loaded 'C:\Windows\SysWOW64\iertutil.dll'.		d : \agent\_work\2\s\src\vctools\VC7Libs\Ship\ATLMFC\Src\MFC\afxmdichildwndex.cpp(1475) : atlTraceGeneral - Warning : ITaskbarList3 is NULL.		The thread 0x2c64 has exited with code 0 (0x0).		The thread 0x4950 has exited with code 0 (0x0).The thread 0x4f9c has exited with code 0 (0x0).The thread 0x500c has exited with code 0 (0x0).	The thread 0x4838 has exited with code 0 (0x0).");


	pDC->Rectangle(0, 0, 500, 500);
	std::string str = GetDocument()->GetMap()->print(basePrinter);
	CRect rcText(0, 0, 500, 100);
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