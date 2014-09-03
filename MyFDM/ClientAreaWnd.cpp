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

	return 0;
}
