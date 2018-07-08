
// FigureMatchAppDlg.h : 头文件
//

#pragma once


// CFigureMatchAppDlg 对话框
class CFigureMatchAppDlg : public CDialogEx
{
// 构造
public:
	CFigureMatchAppDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIGUREMATCHAPP_DIALOG };
#endif

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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	BOOL ShowImage(CDC* pDC, CString strPath, int x, int y);
	afx_msg void OnBnClickedButton3();
};
