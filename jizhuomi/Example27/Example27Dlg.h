
// Example27Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CExample27Dlg �Ի���
class CExample27Dlg : public CDialogEx
{
// ����
public:
	CExample27Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EXAMPLE27_DIALOG };

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
	CStatic m_jzmPicture;
	afx_msg void OnBnClickedLoadPicButton();
};
