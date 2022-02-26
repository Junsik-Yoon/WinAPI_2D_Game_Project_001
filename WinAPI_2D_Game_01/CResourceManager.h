#pragma once

class CTexture;

class CResourceManager
{
	SINGLETON(CResourceManager);
private:
	map<wstring, CTexture*> m_mapTex;//키값,텍스처
	
public:
	CTexture* LoadTexture(const wstring& strKey, const wstring& strPath);
	CTexture* FindTexture(const wstring& strKey);
};

