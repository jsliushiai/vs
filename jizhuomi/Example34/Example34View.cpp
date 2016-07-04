
// Example34View.cpp : CExample34View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CExample34View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CExample34View 构造/析构

CExample34View::CExample34View()
{
	// TODO: 在此处添加构造代码

}

CExample34View::~CExample34View()
{
}

BOOL CExample34View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExample34View 绘制

void CExample34View::OnDraw(CDC* /*pDC*/)
{
	CExample34Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CExample34View 打印


void CExample34View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CExample34View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExample34View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExample34View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CExample34View 诊断

#ifdef _DEBUG
void CExample34View::AssertValid() const
{
	CView::AssertValid();
}

void CExample34View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExample34Doc* CExample34View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExample34Doc)));
	return (CExample34Doc*)m_pDocument;
}
#endif //_DEBUG


// CExample34View 消息处理程序


void CExample34View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMenu menu;       // 菜单（包含主菜单栏和子菜单）   
    CMenu *pSubMenu;  // 右键菜单   
  
    // 加载菜单资源到menu对象   
    menu.LoadMenu(IDR_POPUP_EDIT);   
    // 因为右键菜单是弹出式菜单，不包含主菜单栏，所以取子菜单   
    pSubMenu = menu.GetSubMenu(0);   
    // 将坐标值由客户坐标转换为屏幕坐标   
    ClientToScreen(&point);   
    // 弹出右键菜单，菜单左侧与point.x坐标值对齐   
    pSubMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this); 
	CView::OnRButtonDown(nFlags, point);
}
