
// Example25Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CExample25Dlg �Ի���
class CExample25Dlg : public CDialogEx
{
// ����
public:
	CExample25Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXAMPLE25_DIALOG };

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
	CComboBox m_comboWeb;
	afx_msg void OnCbnSelchangeWebCombo();
};
