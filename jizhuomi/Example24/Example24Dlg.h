
// Example24Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CExample24Dlg �Ի���
class CExample24Dlg : public CDialogEx
{
// ����
public:
	CExample24Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXAMPLE24_DIALOG };

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
	CListBox m_listBox;
	afx_msg void OnLbnSelchangeWebList();
};
