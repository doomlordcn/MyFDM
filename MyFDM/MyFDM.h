
// MyFDM.h : MyFDM Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMyFDMApp:
// �йش����ʵ�֣������ MyFDM.cpp
//

class CMyFDMApp : public CWinApp
{
public:
	CMyFDMApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	bool IsStartedAlready();
};

extern CMyFDMApp theApp;
