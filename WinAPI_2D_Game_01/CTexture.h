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
private: //��ü�����Ҽ����� private���� ����
	CTexture();
	~CTexture();
	friend class CResourceManager; //���ҽ��Ŵ����� �����弱���ؼ� ���ҽ��Ŵ��������� ������ �� �ְ� �Ѵ�
};

