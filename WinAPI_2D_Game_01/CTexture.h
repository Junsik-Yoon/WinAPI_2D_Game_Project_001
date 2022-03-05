#pragma once
#include "CResource.h"


class CTexture :public CResource
{
private:
	HDC		m_hDC;
	HBITMAP m_hBMP;
	BITMAP m_bmpInfo;
public:
	void Load(const wstring& strFilePath);
	HDC GetDC() { return m_hDC; }
	HBITMAP GetBitMap() { return m_hBMP; }
	BITMAP GetBmpInfo() { return m_bmpInfo; }

	UINT GetBmpWidth(){ return m_bmpInfo.bmWidth; }
	UINT GetBmpHeight(){ return m_bmpInfo.bmHeight; }

public:
	CTexture();
	virtual ~CTexture();
};

