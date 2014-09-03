
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "MyFDM.h"

#include "MainFrm.h"
#include "mfchelp.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           
	ID_SB_TRAFFIC_THISMONTH,
	ID_SB_TOTALSPEED,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// 创建一个视图以占用框架的工作区
	//if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	//{
	//	TRACE0("未能创建视图窗口\n");
	//	return -1;
	//}

	//if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
	//	!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	//{
	//	TRACE0("未能创建工具栏\n");
	//	return -1;      // 未能创建
	//}
	if (FALSE == _TBMgr.Create(this)){
		TRACE0("未能创建工具栏\n");
		return -1;
	}
	CBitmap bmp, bmpd;
	bmp.Attach(SBMP(IDB_TOOL0));
	bmpd.Attach(SBMP(IDB_TOOL0_D));
	if (_TB_USE_ALPHA)
	{
		ConvertBmp32WithAlphaToBmp32WithoutAlpha (bmp, GetSysColor (COLOR_3DFACE));
		ConvertBmp32WithAlphaToBmp32WithoutAlpha (bmpd, GetSysColor (COLOR_3DFACE));
	}
	wgTButtonInfo btns [] = 
	{
		wgTButtonInfo (0, TBSTYLE_SEP, _T("")),
		wgTButtonInfo (ID_TUM_LIGHT, TBSTYLE_BUTTON,_T("")),
		wgTButtonInfo (ID_TUM_MEDIUM, TBSTYLE_BUTTON, _T("")),
		wgTButtonInfo (ID_TUM_HEAVY, TBSTYLE_BUTTON, _T("")),
		wgTButtonInfo (0, TBSTYLE_SEP, _T("")),
		wgTButtonInfo (ID_STARTALL, TBSTYLE_BUTTON, _T("")),
		wgTButtonInfo (ID_STOPALL, TBSTYLE_BUTTON, _T("")),
		wgTButtonInfo (ID_PAUSEALLDLDS, TBSTYLE_BUTTON, _T("")),
		wgTButtonInfo (0, TBSTYLE_SEP,_T("")),
		wgTButtonInfo (ID_DLDROPTIONS, TBSTYLE_BUTTON,_T("")),
		wgTButtonInfo (ID_DIAL, TBSTYLE_BUTTON, _T("")),
		wgTButtonInfo (ID_HELP, TBSTYLE_BUTTON, _T("")),
		wgTButtonInfo (0, 0, _T("")),
		wgTButtonInfo (ID_APP_ABOUT, TBSTYLE_BUTTON, _T("")),
		wgTButtonInfo (0, 0, _T("")),
		wgTButtonInfo (0, 0, _T("")),
		wgTButtonInfo (0, 0, _T("")),
		wgTButtonInfo (0, 0, _T("")),
		wgTButtonInfo (0, 0, _T("")),
		wgTButtonInfo (0, 0, _T("")),

	};
	if (FALSE == _TBMgr.InsertGroup (btns, &bmp, &bmpd, sizeof (btns) / sizeof (wgTButtonInfo)))
		return -1;
		_TBMgr.ShowGroup (0, 0);
	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	UINT nID, nStyle;
	int cx;

	m_wndStatusBar.GetPaneInfo (0, nID, nStyle, cx);
	nStyle &= ~ SBPS_NOBORDERS;
	m_wndStatusBar.SetPaneInfo (0, nID, nStyle, cx);

	m_wndReBar.Create(this);
	m_wndReBar.AddBar (&_TBMgr, NULL, NULL, RBBS_FIXEDBMP|RBBS_NOGRIPPER|RBBS_BREAK);

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);
	if (!m_wndView.Create(AfxRegisterWndClass (0, LoadCursor (NULL, IDC_ARROW),
		(HBRUSH) (COLOR_3DFACE+1), NULL), NULL, AFX_WS_DEFAULT_VIEW | WS_CHILD,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	WNDCLASS wc;
	ZeroMemory(&wc, sizeof(WNDCLASS));
	wc.hbrBackground =(HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
	wc.hInstance = AfxGetInstanceHandle();
	wc.lpfnWndProc = ::DefWindowProc;
	wc.lpszClassName = _T("My FDM Main Window");
	cs.lpszClass = wc.lpszClassName;
	return AfxRegisterClass(&wc);
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// 将焦点前移到视图窗口
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// 让视图第一次尝试该命令
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// 否则，执行默认处理
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
