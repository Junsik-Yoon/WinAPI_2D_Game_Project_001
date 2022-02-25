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

CTexture* CResourceManager::FindTexture(const wstring& strKey)
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(strKey);
	
	if (m_mapTex.end() == iter)
	{
		return nullptr;//못찾음
	}
	else
		return iter->second;
	
	return nullptr;
}


CTexture* CResourceManager::LoadTexture(const wstring& strKey, const wstring& strPath)
{
	//이미 있던거면 있던걸 주면된다
	CTexture* pTex = FindTexture(strKey);
	if (nullptr != pTex)
		return pTex;
	
	//없던 거면 추가진행하면 된다

	wstring strFilePath = CPathManager::getInst()->GetContentPath();
	strFilePath += strPath;

	pTex = new CTexture();
	pTex->Load(strFilePath);
	pTex->SetKey(strKey);
	pTex->SetPath(strPath);
	
	m_mapTex.insert(make_pair(strKey,pTex));//makepair두개를 묶어서 하나의 엘리먼트로 만들어줌
	return pTex;
}


