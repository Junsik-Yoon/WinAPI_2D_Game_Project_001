#pragma once

class CTexture;

class CResourceManager
{
	SINGLETON(CResourceManager);
private:
	//텍스처를 모으기 위한 자료구조가 필요
	map<wstring, CTexture*> m_mapTex;//비교를위한 키값과 텍스처값을 동시에 가진다
	

public:
	//키값으로 불러오게
	CTexture* LoadTexture(const wstring& strKey, const wstring& strPath);

	CTexture* FindTexture(const wstring& strKey);
};

