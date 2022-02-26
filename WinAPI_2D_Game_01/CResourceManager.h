#pragma once

class CTexture;

class CResourceManager
{
	SINGLETON(CResourceManager);
private:
	map<wstring,CTexture*> m_mapTex;

public:
	CTexture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	CTexture* FindTexture(const wstring& _strKey);
};

