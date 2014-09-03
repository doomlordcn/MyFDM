// ClientAreaWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "MyFDM.h"
#include "ClientAreaWnd.h"


// CClientAreaWnd

CClientAreaWnd::CClientAreaWnd()
{

}

CClientAreaWnd::~CClientAreaWnd()
{
}


BEGIN_MESSAGE_MAP(CClientAreaWnd, CWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

BOOL CClientAreaWnd::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, NULL,
		(HBRUSH)(COLOR_BTNFACE+1), NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pParent, 0x111))
		return FALSE;

	return TRUE;
}



// CClientAreaWnd 消息处理程序




int CClientAreaWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	if (FALSE == m_plugs2.Create(this))
		return -1;
	return 0;
}


void CClientAreaWnd::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	if (cx == 0 || cy == 0)
		return;

	m_plugs2.MoveWindow(0, 0, cx, cy);
}


void CClientAreaWnd::OnSetFocus(CWnd* pOldWnd)
{
	CWnd::OnSetFocus(pOldWnd);

	// TODO:  在此处添加消息处理程序代码
	m_plugs2.SetFocus();
}
