#pragma once
#include "CRes.h"
class CTexture :public CRes
{
private:
	HDC m_dc;
	HBITMAP m_hBit;
	BITMAP m_bitInfo;

public:
	void Load(const wstring& _strFilePath);

	UINT Width() { return m_bitInfo.bmWidth; }
	UINT Height() { return m_bitInfo.bmHeight; }

	HDC GetDC() { return m_dc; }
private: //자체생성할수없게 private으로 맊고
	CTexture();
	~CTexture();
	friend class CResourceManager; //리소스매니저를 프렌드선언해서 리소스매니저에서만 접근할 수 있게 한다
};

