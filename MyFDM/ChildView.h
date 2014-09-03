
// ChildView.h : CChildView 类的接口
//
#include "ClientAreaWnd.h"
#pragma once


// CChildView 窗口

class CChildView : public CWnd
{
	friend class CMainFrame;
// 构造
public:
	CChildView();

// 特性
public:

// 操作
public:

// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildView();

	// 生成的消息映射函数
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

