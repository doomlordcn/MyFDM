
// MyFDM.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MyFDM.h"
#include "MainFrm.h"
#include "vmsAppMutex.h"
#include "UrlWnd.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyFDMApp

BEGIN_MESSAGE_MAP(CMyFDMApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CMyFDMApp::OnAppAbout)
END_MESSAGE_MAP()


// CMyFDMApp 构造

CMyFDMApp::CMyFDMApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
#ifdef _MANAGED
	// 如果应用程序是利用公共语言运行时支持(/clr)构建的，则:
	//     1) 必须有此附加设置，“重新启动管理器”支持才能正常工作。
	//     2) 在您的项目中，您必须按照生成顺序向 System.Windows.Forms 添加引用。
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: 将以下应用程序 ID 字符串替换为唯一的 ID 字符串；建议的字符串格式
	//为 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("MyFDM.AppID.NoVersion"));

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 CMyFDMApp 对象

CMyFDMApp theApp;
vmsAppMutex appMutex(_T("My Free Download Manager"));

// CMyFDMApp 初始化

BOOL CMyFDMApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	if (IsStartedAlready())
		return FALSE;
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// 使用 RichEdit 控件需要  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));


	// 若要创建主窗口，此代码将创建新的框架窗口
	// 对象，然后将其设置为应用程序的主窗口对象
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// 创建并加载框架及其资源
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);






	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	// 仅当具有后缀时才调用 DragAcceptFiles
	//  在 SDI 应用程序中，这应在 ProcessShellCommand 之后发生
	return TRUE;
}

int CMyFDMApp::ExitInstance()
{
	//TODO: 处理可能已添加的附加资源
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CMyFDMApp 消息处理程序


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };
protected:
	CUrlWnd m_WndURL;
	CUrlWnd m_WndFirm;
	CUrlWnd m_WndSupport;
	CFont m_fntUnderline;
	CFont m_fntRegInfo;
	CFont m_fntWarn;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	m_fntRegInfo.CreateFont(10, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("MS Sans Serif"));
	m_fntWarn.CreateFont(12, 0, 0, 0, FW_LIGHT, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Arail"));
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

// 用于运行对话框的应用程序命令
void CMyFDMApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

bool CMyFDMApp::IsStartedAlready()
{
	if (appMutex.isAnotherInstanceStartedAlready()){
		appMutex.CloseMutex();
		HWND hWnd = FindWindow(_T("My FDM Main Window"), NULL);
		if (IsIconic(hWnd))
			ShowWindow(hWnd, SW_RESTORE);
		SetForegroundWindow(hWnd);
		SetFocus(hWnd);
		return TRUE;
	}
	return FALSE;
}

// CMyFDMApp 消息处理程序


BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CFont* fnt = GetFont();
	LOGFONT lf;
	fnt->GetLogFont(&lf);
	lf.lfUnderline = true;
	m_fntUnderline.CreateFontIndirect(&lf);

	m_WndURL.SubclassDlgItem(IDC__DOWNLOAD, this);//子类化
	m_WndURL.Init();
	m_WndURL.SetUrl(_T("http://www.freedownloadmanager.org/download.htm"));

	CString strVer;
	TCHAR szVer[] = _T("%s %s build %s");
	strVer.Format(szVer, "1", "1","1");
	SetDlgItemText(IDC__VER, strVer);

	m_WndFirm.SubclassDlgItem(IDC__FIRM, this);
	m_WndFirm.Init();
	m_WndFirm.SetUrl(_T("http://www.freedownloadmanager.org"));

	m_WndSupport.SubclassDlgItem(IDC__SUPPORT, this);
	m_WndSupport.Init();
	m_WndSupport.SetUrl(_T("http://www.freedownloadmanager.org/support.htm"));


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


HBRUSH CAboutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->m_hWnd == m_WndFirm.m_hWnd ||
		pWnd->m_hWnd == m_WndURL.m_hWnd ||
		pWnd->m_hWnd == m_WndSupport.m_hWnd){
		pDC->SetTextColor(GetSysColor(26));
		pDC->SelectObject(&m_fntUnderline);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
