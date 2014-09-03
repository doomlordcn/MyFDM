#ifndef ClientAreaWnd_h__
#define ClientAreaWnd_h__

#pragma once


// CClientAreaWnd

class CClientAreaWnd : public CWnd
{

public:
	CClientAreaWnd();
	virtual ~CClientAreaWnd();
	BOOL Create (CWnd *pParent);

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
#endif // ClientAreaWnd_h__


