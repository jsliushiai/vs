
// Example29Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CExample29Dlg �Ի���
class CExample29Dlg : public CDialogEx
{
// ����
public:
	CExample29Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXAMPLE29_DIALOG };

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
	CListCtrl m_programLangList;
	afx_msg void OnNMClickProgramLangList(NMHDR *pNMHDR, LRESULT *pResult);
};
