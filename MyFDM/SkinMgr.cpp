#include "StdAfx.h"
#include "SkinMgr.h"


CSkinMgr::CSkinMgr()
{
}


CSkinMgr::~CSkinMgr()
{
}

HBITMAP CSkinMgr::bmp(UINT nID)
{
	static UINT IDs[] = {
		IDB_TOOL0, IDB_TOOL0_D
	};

	static LPCTSTR ppszName[] = {
		_T("tool0"), _T("tool0_d")
	};
	ASSERT(sizeof(IDs) / sizeof(UINT) == sizeof(ppszName) / sizeof(LPCTSTR));
	for (int i = 0; i < sizeof(IDs) / sizeof(UINT);i++)
	{
		if (IDs[i] == nID)
			return bmp_x(nID, ppszName[i]);
	}
	return bmp_x(nID, NULL);
}

HBITMAP CSkinMgr::bmp_x(UINT nID, LPCTSTR pszName)
{
	return (HBITMAP)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(nID), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
}
