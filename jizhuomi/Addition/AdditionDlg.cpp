
// AdditionDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Addition.h"
#include "AdditionDlg.h"
#include "afxdialogex.h"
#include "AddSheet.h"

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


// CAdditionDlg �Ի���




CAdditionDlg::CAdditionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAdditionDlg::IDD, pParent)
	, m_editSummand(0)
	, m_editAddend(0)
	, m_editSum(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pTipDlg = NULL;
}

void CAdditionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SUMMAND_EDIT, m_editSummand);
	DDX_Text(pDX, IDC_ADDEND_EDIT, m_editAddend);
	DDX_Text(pDX, IDC_SUM_EDIT, m_editSum);
}

BEGIN_MESSAGE_MAP(CAdditionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CAdditionDlg::OnClickedAddButton)
	ON_BN_CLICKED(IDC_INSTRUCT_BUTTON, &CAdditionDlg::OnBnClickedInstructButton)
END_MESSAGE_MAP()


// CAdditionDlg ��Ϣ�������

BOOL CAdditionDlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

CAdditionDlg::~CAdditionDlg(){
	if(NULL != m_pTipDlg){
		delete m_pTipDlg;
	}
}

void CAdditionDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAdditionDlg::OnPaint()
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
HCURSOR CAdditionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAdditionDlg::OnClickedAddButton()
{
	
	//ģ̬
	INT_PTR nRes;
	//CTipDlg tipDlg;
	//nRes = tipDlg.DoModal();
	nRes = MessageBox(_T("��ȷ��Ҫ���мӷ�������"),_T("�ӷ�������"),MB_OKCANCEL | MB_ICONQUESTION);
	if(IDCANCEL == nRes){
		return;
	}
	/*
	//��ģ̬
	if(NULL == m_pTipDlg){
		m_pTipDlg = new CTipDlg();
		m_pTipDlg->Create(IDD_TIP_DIALOG,this);
	}
	m_pTipDlg->ShowWindow(SW_SHOW);
	*/
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);

	m_editSum = m_editSummand + m_editAddend;

	UpdateData(false);
}


void CAdditionDlg::OnBnClickedInstructButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAddSheet sheet(_T("ʹ��˵��"));   
    // �������ԶԻ���Ϊ�򵼶Ի���   
    //sheet.SetWizardMode();   
    // ��ģ̬�򵼶Ի���   
    sheet.DoModal();
}
