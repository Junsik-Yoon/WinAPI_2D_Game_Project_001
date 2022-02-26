#include "pch.h"
#include "CResourceManager.h"
#include "CPathManager.h"
#include "CTexture.h"
CResourceManager::CResourceManager()
{

}
CResourceManager::~CResourceManager()
{
	//텍스처들은 리소스매니저에서 해제해줘야한다
	map<wstring, CTexture*>::iterator iter = m_mapTex.begin();
	for (; iter != m_mapTex.end(); ++iter)
	{
		delete iter->second;
	}
}

CTexture* CResourceManager::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{

	CTexture* pTex = FindTexture(_strKey);
	if (nullptr != pTex) // 키가 이미 있으면
	{
		return pTex;
	}

	//없으면 

	wstring strFilePath = CPathManager::GetInst()->GetContentPath();
	strFilePath += _strRelativePath;
	
	pTex = new CTexture;
	pTex->Load(strFilePath);

	pTex->SetKey(_strKey);
	pTex->SetRelativePath(_strRelativePath); //리소스가 스스로 경로랑 키값을 알도록 세팅

	m_mapTex.insert(make_pair(_strKey, pTex));

	return pTex;
}

CTexture* CResourceManager::FindTexture(const wstring& _strKey)
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(_strKey);//찾아서 이터레이터로 반환
	if (iter == m_mapTex.end())
	{
		return nullptr; //못찾았으면 nullptr 반환
	}
	return iter->second;//찾으면 second 값을 주면 된다
	
}
