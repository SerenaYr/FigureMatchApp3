// MyOutputDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FigureMatchApp.h"
#include "MyOutputDlg.h"
#include "afxdialogex.h"


// CMyOutputDlg 对话框

IMPLEMENT_DYNAMIC(CMyOutputDlg, CDialogEx)

CMyOutputDlg::CMyOutputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMyOutputDlg::~CMyOutputDlg()
{
}

void CMyOutputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyOutputDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyOutputDlg 消息处理程序
