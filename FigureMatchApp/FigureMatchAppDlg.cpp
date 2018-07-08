
// FigureMatchAppDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FigureMatchApp.h"
#include "FigureMatchAppDlg.h"
#include "afxdialogex.h"
#include "MyOutputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFigureMatchAppDlg 对话框



CFigureMatchAppDlg::CFigureMatchAppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FIGUREMATCHAPP_DIALOG, pParent)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CFigureMatchAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFigureMatchAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CFigureMatchAppDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFigureMatchAppDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CFigureMatchAppDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CFigureMatchAppDlg 消息处理程序

BOOL CFigureMatchAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFigureMatchAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFigureMatchAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFigureMatchAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CFigureMatchAppDlg::ShowImage(CDC* pDC, CString strPath, int x, int y)
{

	IPicture *pPic = NULL;
	OleLoadPicturePath(CComBSTR(strPath.GetBuffer()), (LPUNKNOWN)NULL, 0, 0, IID_IPicture, (LPVOID*)&pPic);
	if (NULL == pPic)
	{
		return FALSE;
	}

	// 获取图像宽和高,注意这里的宽和高不是图像的分辨率
	OLE_XSIZE_HIMETRIC hmWidth;
	OLE_YSIZE_HIMETRIC hmHeight;
	pPic->get_Width(&hmWidth);
	pPic->get_Height(&hmHeight);

	// 将图像宽度和高度单位转化为像素单位
	//#define HIMETRIC_PER_INCH 2540
	//int nPicWidth =  MulDiv(hmWidth, GetDeviceCaps(GetDC()->m_hDC, LOGPIXELSX),2540);
	//int nPicHeight = MulDiv(hmHeight, GetDeviceCaps(GetDC()->m_hDC, LOGPIXELSY),2540);

	// 获取显示图片窗口的宽度和高度
	RECT rtWnd;
	pDC->GetWindow()->GetWindowRect(&rtWnd);
	int iWndWidth = rtWnd.right - rtWnd.left;
	int iWndHeight = rtWnd.bottom - rtWnd.top;

	if (FAILED(pPic->Render(*pDC, x, y, iWndWidth, iWndHeight, 0, hmHeight, hmWidth, -hmHeight, NULL)))
	{
		pPic->Release();
		return false;
	}

	//记得释放资源，不然会导致内存泄露
	pPic->Release();

	return true;
}

void CFigureMatchAppDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(true, "jpg", "*.jpg", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"JPEG文件(*.jpg)|*.jpg|GIF文件(*.gif)|*.gif|bmp文件(*.bmp)|*.bmp|", NULL);
	if (dlg.DoModal() == IDOK)
	{
		//设置静态控件的样式，使其可以使用位图，并使位图显示居中
		((CStatic*)GetDlgItem(IDC_INPUT))->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);

		CDC *pDC = NULL;
		pDC = GetDlgItem(IDC_INPUT)->GetDC();
		ShowImage(pDC, dlg.GetPathName(), 0, 0);

		ReleaseDC(pDC);	// 记得释放资源，不然会导致内存泄露
	}
}


void CFigureMatchAppDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(true, "jpg", "*.jpg", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"JPEG文件(*.jpg)|*.jpg|GIF文件(*.gif)|*.gif|bmp文件(*.bmp)|*.bmp|", NULL);
	if (dlg.DoModal() == IDOK)
	{
		//设置静态控件的样式，使其可以使用位图，并使位图显示居中
		((CStatic*)GetDlgItem(IDC_SOURCE))->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE);

		CDC *pDC = NULL;
		pDC = GetDlgItem(IDC_SOURCE)->GetDC();
		ShowImage(pDC, dlg.GetPathName(), 0, 0);

		ReleaseDC(pDC);	// 记得释放资源，不然会导致内存泄露
	}
}


void CFigureMatchAppDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CMyOutputDlg dlg;
	dlg.DoModal();   // 弹出新的对话框，显示匹配结果
}
