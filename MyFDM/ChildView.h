
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
	CClientAreaWnd m_wndClient;
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

