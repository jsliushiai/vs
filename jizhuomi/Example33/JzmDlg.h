#pragma once


// CJzmDlg �Ի���

class CJzmDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CJzmDlg)

public:
	CJzmDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CJzmDlg();

// �Ի�������
	enum { IDD = IDD_JIZHUOMI_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
