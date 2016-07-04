
// Example33Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "JzmDlg.h"
#include "AndroidDlg.h"


// CExample33Dlg �Ի���
class CExample33Dlg : public CDialogEx
{
// ����
public:
	CExample33Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXAMPLE33_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CJzmDlg m_jzmDlg;
	CAndroidDlg m_androidDlg;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
