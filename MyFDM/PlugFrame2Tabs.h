#pragma once


// CPlugFrame2Tabs

#ifndef PlugFrame2Tabs_h__
#define PlugFrame2Tabs_h__

class CPlugFrame2Tabs : public CTabCtrl
{

public:
	CPlugFrame2Tabs();
	virtual ~CPlugFrame2Tabs();
	BOOL Create(CWnd* pParent);
protected:
	CFont m_itemsFont;
	class CPluginFrame2 *m_parent;
	DECLARE_MESSAGE_MAP()
};
#endif // PlugFrame2Tabs_h__


