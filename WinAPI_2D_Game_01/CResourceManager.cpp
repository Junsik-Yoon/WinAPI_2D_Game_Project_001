#include "pch.h"
#include "CResourceManager.h"
#include "CTexture.h"
#include "CSound.h"

CResourceManager::CResourceManager()
{
	m_mapTex = {};
	m_mapSound = {};
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
	m_mapTex.clear();
	//�ڷᱸ���� ����� ��� sound ����
	for (map<wstring, CSound*>::iterator iter = m_mapSound.begin(); iter != m_mapSound.end(); ++iter)
	{
		if (nullptr != iter->second)
		{
			delete iter->second;
		}
	}
	m_mapSound.clear();
}




CTexture* CResourceManager::LoadTexture(const wstring& strKey, const wstring& strPath)
{
	//�̹� Ű���� ���� ��
	CTexture* pTex = FindTexture(strKey);
	if (nullptr != pTex)
		return pTex;
	
	//���� �� �����Ҵ�
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
		return nullptr;//��ã��
	}
	else
	{
		return iter->second;
	}
}

CTexture* CResourceManager::CreateTexture(const wstring& strKey, UINT width, UINT height)
{
	CTexture* pTex = FindTexture(strKey);
	if (nullptr != pTex)
	{
		return pTex;
	}
	pTex = new CTexture();
	pTex->Create(width, height);
	pTex->SetKey(strKey);
	m_mapTex.insert(make_pair(strKey, pTex));
	return pTex;
}

CSound* CResourceManager::FindSound(const wstring& strKey)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(strKey);

	if (m_mapSound.end() == iter)
	{
		return nullptr;//��ã��
	}
	else
		return iter->second;
}

CSound* CResourceManager::LoadSound(const wstring& strKey, const wstring& strRelativePath)
{
	//�̹� Ű���� ���� ��
	CSound* pSound = FindSound(strKey);
	if (nullptr != pSound)
		return pSound;

	//���� �� �����Ҵ�
	wstring strFilePath = CPathManager::getInst()->GetContentRelativePath();
	strFilePath += strRelativePath;

	pSound = new CSound();
	pSound-> Load(strFilePath);
	pSound->SetKey(strKey);
	pSound->SetPath(strRelativePath);

	m_mapSound.insert(make_pair(strKey, pSound));
	return pSound;
}


