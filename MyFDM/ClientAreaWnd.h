#ifndef ClientAreaWnd_h__
#define ClientAreaWnd_h__
#include "PluginFrame2.h"
#pragma once


// CClientAreaWnd

class CClientAreaWnd : public CWnd
{

public:
	CClientAreaWnd();
	virtual ~CClientAreaWnd();
	BOOL Create (CWnd *pParent);

protected:
	CPluginFrame2 m_plugs2;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
};
#endif // ClientAreaWnd_h__


