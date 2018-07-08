#pragma once


// CMyOutputDlg 对话框

class CMyOutputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMyOutputDlg)

public:
	CMyOutputDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyOutputDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
