#include "pch.h"
#include "CResourceManager.h"
#include "CPathManager.h"
#include "CTexture.h"
CResourceManager::CResourceManager()
{

}
CResourceManager::~CResourceManager()
{
	//�ؽ�ó���� ���ҽ��Ŵ������� ����������Ѵ�
	map<wstring, CTexture*>::iterator iter = m_mapTex.begin();
	for (; iter != m_mapTex.end(); ++iter)
	{
		delete iter->second;
	}
}

CTexture* CResourceManager::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{

	CTexture* pTex = FindTexture(_strKey);
	if (nullptr != pTex) // Ű�� �̹� ������
	{
		return pTex;
	}

	//������ 

	wstring strFilePath = CPathManager::GetInst()->GetContentPath();
	strFilePath += _strRelativePath;
	
	pTex = new CTexture;
	pTex->Load(strFilePath);

	pTex->SetKey(_strKey);
	pTex->SetRelativePath(_strRelativePath); //���ҽ��� ������ ��ζ� Ű���� �˵��� ����

	m_mapTex.insert(make_pair(_strKey, pTex));

	return pTex;
}

CTexture* CResourceManager::FindTexture(const wstring& _strKey)
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(_strKey);//ã�Ƽ� ���ͷ����ͷ� ��ȯ
	if (iter == m_mapTex.end())
	{
		return nullptr; //��ã������ nullptr ��ȯ
	}
	return iter->second;//ã���� second ���� �ָ� �ȴ�
	
}
