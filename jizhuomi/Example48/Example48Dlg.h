
// Example48Dlg.h : 头文件
//

#pragma once


// CExample48Dlg 对话框
class CExample48Dlg : public CDialogEx
{
// 构造
public:
	CExample48Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EXAMPLE48_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nTextX;
	int m_nTextY;
	CFont m_newFont;   // 新字体   
	CFont *m_pOldFont; // 选择新字体之前的字体  
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
