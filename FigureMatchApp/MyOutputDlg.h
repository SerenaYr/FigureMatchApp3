#pragma once


// CMyOutputDlg �Ի���

class CMyOutputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMyOutputDlg)

public:
	CMyOutputDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyOutputDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
