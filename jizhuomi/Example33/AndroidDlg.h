#pragma once


// CAndroidDlg �Ի���

class CAndroidDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAndroidDlg)

public:
	CAndroidDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAndroidDlg();

// �Ի�������
	enum { IDD = IDD_ANDROID_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
