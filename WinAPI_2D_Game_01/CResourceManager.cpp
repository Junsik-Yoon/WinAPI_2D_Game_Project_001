#include "pch.h"
#include "CResourceManager.h"
#include "CTexture.h"

CResourceManager::CResourceManager()
{
	m_mapTex = {};
}
CResourceManager::~CResourceManager()
{
	for (map<wstring, CTexture*>::iterator iter = m_mapTex.begin(); iter != m_mapTex.end(); ++iter)
	{
		if (nullptr != iter->second)
		{
			delete iter->second;
		}
	}
}




CTexture* CResourceManager::LoadTexture(const wstring& strKey, const wstring& strPath)
{
	//이미 키값이 있을 시
	CTexture* pTex = FindTexture(strKey);
	if (nullptr != pTex)
		return pTex;
	
	//없을 시 동적할당
	wstring strFilePath = CPathManager::getInst()->GetContentPath();
	strFilePath += strPath;

	pTex = new CTexture();
	pTex->Load(strFilePath);
	pTex->SetKey(strKey);
	pTex->SetPath(strPath);
	
	m_mapTex.insert(make_pair(strKey,pTex));
	return pTex;
}

CTexture* CResourceManager::FindTexture(const wstring& strKey)
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(strKey);

	if (m_mapTex.end() == iter)
	{
		return nullptr;//못찾음
	}
	else
		return iter->second;
}


