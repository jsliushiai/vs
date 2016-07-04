
// Example29Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Example29.h"
#include "Example29Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CExample29Dlg �Ի���




CExample29Dlg::CExample29Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExample29Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExample29Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRAM_LANG_LIST, m_programLangList);
}

BEGIN_MESSAGE_MAP(CExample29Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_PROGRAM_LANG_LIST, &CExample29Dlg::OnNMClickProgramLangList)
END_MESSAGE_MAP()


// CExample29Dlg ��Ϣ�������

BOOL CExample29Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CRect rect;
	m_programLangList.GetClientRect(&rect);
	m_programLangList.SetExtendedStyle(m_programLangList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES); 
	m_programLangList.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width()/3, 0);   
    m_programLangList.InsertColumn(1, _T("2012.02����"), LVCFMT_CENTER, rect.Width()/3, 1);   
    m_programLangList.InsertColumn(2, _T("2011.02����"), LVCFMT_CENTER, rect.Width()/3, 2); 

	m_programLangList.InsertItem(0, _T("Java"));   
    m_programLangList.SetItemText(0, 1, _T("1"));   
    m_programLangList.SetItemText(0, 2, _T("1"));   
    m_programLangList.InsertItem(1, _T("C"));   
    m_programLangList.SetItemText(1, 1, _T("2"));   
    m_programLangList.SetItemText(1, 2, _T("2"));   
    m_programLangList.InsertItem(2, _T("C#"));   
    m_programLangList.SetItemText(2, 1, _T("3"));   
    m_programLangList.SetItemText(2, 2, _T("6"));   
    m_programLangList.InsertItem(3, _T("C++"));   
    m_programLangList.SetItemText(3, 1, _T("4"));   
    m_programLangList.SetItemText(3, 2, _T("3")); 

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CExample29Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExample29Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CExample29Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExample29Dlg::OnNMClickProgramLangList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	CString strLangName;
	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;

	if(-1 != pNMListView->iItem){
		strLangName = m_programLangList.GetItemText(pNMListView->iItem, 0);   
        // ��ѡ���������ʾ��༭����   
        SetDlgItemText(IDC_LANG_SEL_EDIT, strLangName); 
	}
}
