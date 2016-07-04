
// Example23Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Example23.h"
#include "Example23Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CExample23Dlg 对话框




CExample23Dlg::CExample23Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExample23Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExample23Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_CHECK3, m_check3);
	DDX_Control(pDX, IDC_CHECK4, m_check4);
	DDX_Control(pDX, IDC_CHECK5, m_check5);
	DDX_Control(pDX, IDC_CHECK6, m_check6);
}

BEGIN_MESSAGE_MAP(CExample23Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PORTAL_RADIO, &CExample23Dlg::OnBnClickedPortalRadio)
	ON_BN_CLICKED(IDC_FORUM_RADIO, &CExample23Dlg::OnBnClickedForumRadio)
	ON_BN_CLICKED(IDC_BLOG_RADIO, &CExample23Dlg::OnBnClickedBlogRadio)
	ON_BN_CLICKED(IDOK, &CExample23Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CExample23Dlg 消息处理程序

BOOL CExample23Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CheckDlgButton(IDC_PORTAL_RADIO, 1);   
    OnBnClickedPortalRadio();  

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CExample23Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CExample23Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CExample23Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExample23Dlg::OnBnClickedPortalRadio()
{
	// TODO: 在此添加控件通知处理程序代码
	InitAllCheckBoxStatus();   
    m_check2.EnableWindow(TRUE);   
    m_check5.EnableWindow(TRUE);
	m_check2.SetCheck(1);   
    m_check5.SetCheck(1);  
}


void CExample23Dlg::OnBnClickedForumRadio()
{
	// TODO: 在此添加控件通知处理程序代码
	InitAllCheckBoxStatus();   
    m_check3.EnableWindow(TRUE);   
    m_check6.EnableWindow(TRUE); 
	m_check3.SetCheck(1);   
    m_check6.SetCheck(1);  
}


void CExample23Dlg::OnBnClickedBlogRadio()
{
	// TODO: 在此添加控件通知处理程序代码
	InitAllCheckBoxStatus();   
    m_check1.EnableWindow(TRUE);   
    m_check4.EnableWindow(TRUE); 
	m_check1.SetCheck(1);   
    m_check4.SetCheck(1); 
}


void CExample23Dlg::InitAllCheckBoxStatus()
{
	m_check1.EnableWindow(FALSE);   
    m_check2.EnableWindow(FALSE);   
    m_check3.EnableWindow(FALSE);   
    m_check4.EnableWindow(FALSE);   
    m_check5.EnableWindow(FALSE);   
    m_check6.EnableWindow(FALSE);   
  
    // 全部非选中   
    m_check1.SetCheck(0);   
    m_check2.SetCheck(0);   
    m_check3.SetCheck(0);   
    m_check4.SetCheck(0);   
    m_check5.SetCheck(0);   
    m_check6.SetCheck(0); 
}


void CExample23Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	    CString strWebsiteSel;         // 选择的网站   
  
    // 若选中“鸡啄米”则将其加入结果字符串   
    if (1 == m_check1.GetCheck())   
    {   
        strWebsiteSel += _T("鸡啄米 ");   
    }   
    // 若选中“新浪”则将其加入结果字符串   
    if (1 == m_check2.GetCheck())   
    {   
        strWebsiteSel += _T("新浪 ");   
    }   
    // 若选中“天涯论坛”则将其加入结果字符串   
    if (1 == m_check3.GetCheck())   
    {   
        strWebsiteSel += _T("天涯论坛 ");   
    }   
    // 若选中“韩寒博客”则将其加入结果字符串   
    if (1 == m_check4.GetCheck())   
    {   
        strWebsiteSel += _T("韩寒博客 ");   
    }   
    // 若选中“网易”则将其加入结果字符串   
    if (1 == m_check5.GetCheck())   
    {   
        strWebsiteSel += _T("网易 ");   
    }   
    // 若选中“凤凰网论坛”则将其加入结果字符串   
    if (1 == m_check6.GetCheck())   
    {   
        strWebsiteSel += _T("凤凰网论坛 ");   
    }  
	SetDlgItemText(IDC_WEBSITE_SEL_EDIT, strWebsiteSel); 
	//CDialogEx::OnOK();
}
