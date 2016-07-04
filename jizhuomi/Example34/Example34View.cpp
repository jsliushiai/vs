
// Example34View.cpp : CExample34View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Example34.h"
#endif

#include "Example34Doc.h"
#include "Example34View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExample34View

IMPLEMENT_DYNCREATE(CExample34View, CView)

BEGIN_MESSAGE_MAP(CExample34View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CExample34View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CExample34View ����/����

CExample34View::CExample34View()
{
	// TODO: �ڴ˴���ӹ������

}

CExample34View::~CExample34View()
{
}

BOOL CExample34View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExample34View ����

void CExample34View::OnDraw(CDC* /*pDC*/)
{
	CExample34Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExample34View ��ӡ


void CExample34View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CExample34View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExample34View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExample34View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CExample34View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	//ClientToScreen(&point);
	//OnContextMenu(this, point);
}

void CExample34View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExample34View ���

#ifdef _DEBUG
void CExample34View::AssertValid() const
{
	CView::AssertValid();
}

void CExample34View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExample34Doc* CExample34View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExample34Doc)));
	return (CExample34Doc*)m_pDocument;
}
#endif //_DEBUG


// CExample34View ��Ϣ�������


void CExample34View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMenu menu;       // �˵����������˵������Ӳ˵���   
    CMenu *pSubMenu;  // �Ҽ��˵�   
  
    // ���ز˵���Դ��menu����   
    menu.LoadMenu(IDR_POPUP_EDIT);   
    // ��Ϊ�Ҽ��˵��ǵ���ʽ�˵������������˵���������ȡ�Ӳ˵�   
    pSubMenu = menu.GetSubMenu(0);   
    // ������ֵ�ɿͻ�����ת��Ϊ��Ļ����   
    ClientToScreen(&point);   
    // �����Ҽ��˵����˵������point.x����ֵ����   
    pSubMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this); 
	CView::OnRButtonDown(nFlags, point);
}
