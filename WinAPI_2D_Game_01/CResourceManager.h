#pragma once

class CTexture;

class CResourceManager
{
	SINGLETON(CResourceManager);
private:
	map<wstring, CTexture*> m_mapTex;//Ű��,�ؽ�ó
	
public:
	CTexture* LoadTexture(const wstring& strKey, const wstring& strPath);
	CTexture* FindTexture(const wstring& strKey);
};

