
// Example48Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Example48.h"
#include "Example48Dlg.h"
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


// CExample48Dlg �Ի���




CExample48Dlg::CExample48Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExample48Dlg::IDD, pParent)
	, m_nTextX(0)
	, m_nTextY(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_nTextX = 260;   
    m_nTextY = 10;   
    m_pOldFont = NULL;  
}

void CExample48Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExample48Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CExample48Dlg ��Ϣ�������

BOOL CExample48Dlg::OnInitDialog()
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
	m_newFont.CreatePointFont(180, _T("����"));   
  
    // ���ö�ʱ������ʱʱ��Ϊ200ms   
    SetTimer(1,200,NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CExample48Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExample48Dlg::OnPaint()
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
		CPaintDC dc(this); // device context for painting   
        // ����m_newFont���������Ϊ��ǰ���壬����֮ǰ������ָ�뱣�浽m_pOldFont   
        m_pOldFont = (CFont*)dc.SelectObject(&m_newFont);   
        // ����   
        dc.SetBkMode(TRANSPARENT); //���ñ���Ϊ͸����   
        // �����ı���ɫΪ��ɫ   
        dc.SetTextColor(RGB(255,0,0));   
        // ��ָ��λ������ı�   
        dc.TextOut(m_nTextX,10,_T("��ӭ���������ף�"));   
        // �����ı���ɫΪ��ɫ   
        dc.SetTextColor(RGB(0,255,0));   
        // ��ָ��λ������ı�   
        dc.TextOut(10,m_nTextY,_T("лл��עwww.jizhuomi.com"));   
        // �ָ���ǰ������   
        dc.SelectObject(m_pOldFont);  
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CExample48Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExample48Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	LOGFONT logFont;   
    // ��ȡm_newFont�����LOGFONT�ṹ   
    m_newFont.GetLogFont(&logFont);   
  
    // ��m_nTextX��ֵ��5   
    m_nTextX -= 5;   
    // ���m_nTextXС��10�����ı�����ӭ���������ס��ص���ʼλ��   
    if (m_nTextX < 10)   
        m_nTextX = 260;   
  
    // ��m_nTextY��ֵ��һ���ַ��߶�   
    m_nTextY += abs(logFont.lfHeight);   
    // ���m_nTextY����260�����ı���лл��עwww.jizhuomi.com���ص���ʼλ��   
    if (m_nTextY >260)   
        m_nTextY = 10;   
  
    // ʹ���ڿͻ�����Ч��֮��ͻ��ػ�   
    Invalidate();   
  
	CDialogEx::OnTimer(nIDEvent);
}
