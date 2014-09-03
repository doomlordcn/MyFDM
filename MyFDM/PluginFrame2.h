#ifndef PluginFrame2_h__
#define PluginFrame2_h__

#include "PlugFrame2Tabs.h"
#pragma once


// CPluginFrame2

class CPluginFrame2 : public CWnd
{

public:
	CPluginFrame2();
	virtual ~CPluginFrame2();
	BOOL Create(CWnd* pParent);
protected:
	CPlugFrame2Tabs m_wndTabs;
	class CMainFrame* m_pMainFrame;
	BOOL Initialize();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
#endif // PluginFrame2_h__


