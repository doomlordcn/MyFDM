
// MyFDM.cpp : ����Ӧ�ó��������Ϊ��
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


// CMyFDMApp ����

CMyFDMApp::CMyFDMApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
#ifdef _MANAGED
	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���:
	//     1) �����д˸������ã�������������������֧�ֲ�������������
	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("MyFDM.AppID.NoVersion"));

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CMyFDMApp ����

CMyFDMApp theApp;
vmsAppMutex appMutex(_T("My Free Download Manager"));

// CMyFDMApp ��ʼ��

BOOL CMyFDMApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	if (IsStartedAlready())
		return FALSE;
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// ʹ�� RichEdit �ؼ���Ҫ  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));


	// ��Ҫ���������ڣ��˴��뽫�����µĿ�ܴ���
	// ����Ȼ��������ΪӦ�ó���������ڶ���
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// ���������ؿ�ܼ�����Դ
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);






	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� SDI Ӧ�ó����У���Ӧ�� ProcessShellCommand ֮����
	return TRUE;
}

int CMyFDMApp::ExitInstance()
{
	//TODO: �����������ӵĸ�����Դ
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CMyFDMApp ��Ϣ�������


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };
protected:
	CUrlWnd m_WndURL;
	CUrlWnd m_WndFirm;
	CUrlWnd m_WndSupport;
	CFont m_fntUnderline;
	CFont m_fntRegInfo;
	CFont m_fntWarn;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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

// �������жԻ����Ӧ�ó�������
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

// CMyFDMApp ��Ϣ�������


BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CFont* fnt = GetFont();
	LOGFONT lf;
	fnt->GetLogFont(&lf);
	lf.lfUnderline = true;
	m_fntUnderline.CreateFontIndirect(&lf);

	m_WndURL.SubclassDlgItem(IDC__DOWNLOAD, this);//���໯
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
	// �쳣:  OCX ����ҳӦ���� FALSE
}


HBRUSH CAboutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd->m_hWnd == m_WndFirm.m_hWnd ||
		pWnd->m_hWnd == m_WndURL.m_hWnd ||
		pWnd->m_hWnd == m_WndSupport.m_hWnd){
		pDC->SetTextColor(GetSysColor(26));
		pDC->SelectObject(&m_fntUnderline);
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}
