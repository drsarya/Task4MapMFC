
// Task4Doc.cpp : implementation of the CMap4Doc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Task4.h"
#endif

#include "Task4Doc.h"
#include <iostream>
#include <fstream>
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMap4Doc

IMPLEMENT_DYNCREATE(CMap4Doc, CDocument)

BEGIN_MESSAGE_MAP(CMap4Doc, CDocument)
END_MESSAGE_MAP()


// CMap4Doc construction/destruction

CMap4Doc::CMap4Doc() noexcept
{
	// TODO: add one-time construction code here

}

MyMap* CMap4Doc::GetMap()
{
	return  map;
}

CMap4Doc::~CMap4Doc()
{
}

BOOL CMap4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}


std::string  to_string(const CString& cst)
{
	return CT2A(cst.GetString());
}

// CMap4Doc serialization

void CMap4Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		string text  = map->toFile();
		ar.Write(text.c_str(), text.size());
	}
	else
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		std::string result;
		std::string line;
		std::ifstream in(ar.GetFile()->GetFilePath());
		if (in.is_open())
		{
			while (getline(in, line))
			{
				result += line;
				result += " ";
			}
			map->fromFile(result);
		}
		in.close();
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMap4Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMap4Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMap4Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl* pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMap4Doc diagnostics

#ifdef _DEBUG
void CMap4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMap4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMap4Doc commands
