// PlugFrame2Tabs.cpp : 实现文件
//

#include "stdafx.h"
#include "MyFDM.h"
#include "PlugFrame2Tabs.h"


// CPlugFrame2Tabs

CPlugFrame2Tabs::CPlugFrame2Tabs()
{

}

CPlugFrame2Tabs::~CPlugFrame2Tabs()
{
}


BEGIN_MESSAGE_MAP(CPlugFrame2Tabs, CTabCtrl)
END_MESSAGE_MAP()

BOOL CPlugFrame2Tabs::Create(CWnd* pParent)
{
	CRect rc(50, 50, 275, 70);

	if (FALSE == CTabCtrl::Create(TCS_SINGLELINE | TCS_RIGHTJUSTIFY | TCS_FOCUSNEVER,
		rc, pParent, 0x5113))
		return FALSE;

	m_parent = (CPluginFrame2*)pParent;



	LOGFONT lf;
	NONCLIENTMETRICS nm;

	ZeroMemory(&nm, sizeof(nm));
	nm.cbSize = sizeof(nm);
	SystemParametersInfo(SPI_GETNONCLIENTMETRICS, nm.cbSize, &nm, 0);
	lf = nm.lfMenuFont;
	lf.lfCharSet = DEFAULT_CHARSET;

	m_itemsFont.CreateFontIndirect(&lf);

	SetFont(&m_itemsFont, FALSE);

	ShowWindow(SW_SHOW);

	return TRUE;
}



// CPlugFrame2Tabs 消息处理程序


