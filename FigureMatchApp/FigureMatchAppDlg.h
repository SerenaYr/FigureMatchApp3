
// FigureMatchAppDlg.h : ͷ�ļ�
//

#pragma once


// CFigureMatchAppDlg �Ի���
class CFigureMatchAppDlg : public CDialogEx
{
// ����
public:
	CFigureMatchAppDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIGUREMATCHAPP_DIALOG };
#endif

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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	BOOL ShowImage(CDC* pDC, CString strPath, int x, int y);
	afx_msg void OnBnClickedButton3();
};
