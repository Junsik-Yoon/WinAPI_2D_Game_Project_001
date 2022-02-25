#pragma once
#include "CResource.h"


class CTexture :public CResource
{
private:
	HDC		m_hDC;
	HBITMAP m_hBMP;
public:
	void Load(const wstring& strFilePath);
	HDC GetDC() { return m_hDC; }
	HBITMAP GETBitMap() { return m_hBMP; }
public:
	CTexture();
	virtual ~CTexture();
};

