
// ChildView.h : CChildView ��Ľӿ�
//
#include "ClientAreaWnd.h"
#pragma once


// CChildView ����

class CChildView : public CWnd
{
	friend class CMainFrame;
// ����
public:
	CChildView();

// ����
public:

// ����
public:

// ��д
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CChildView();

	// ���ɵ���Ϣӳ�亯��
protected:
	void ApplySize(int cx, int cy);
	CClientAreaWnd m_wndClient;
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
};

