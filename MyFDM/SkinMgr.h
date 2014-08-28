#ifndef SkinMgr_h__
#define SkinMgr_h__
#define SBMP(id) _SkinMgr.bmp(id)
#pragma once
class CSkinMgr
{
public:
	CSkinMgr();
	~CSkinMgr();
	HBITMAP bmp(UINT nID);
	HBITMAP bmp_x(UINT nID, LPCTSTR pszName);

};
#endif // SkinMgr_h__

