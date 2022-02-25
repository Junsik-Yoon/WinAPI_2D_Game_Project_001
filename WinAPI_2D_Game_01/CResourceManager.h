#pragma once

class CTexture;

class CResourceManager
{
	SINGLETON(CResourceManager);
private:
	//�ؽ�ó�� ������ ���� �ڷᱸ���� �ʿ�
	map<wstring, CTexture*> m_mapTex;//�񱳸����� Ű���� �ؽ�ó���� ���ÿ� ������
	

public:
	//Ű������ �ҷ�����
	CTexture* LoadTexture(const wstring& strKey, const wstring& strPath);

	CTexture* FindTexture(const wstring& strKey);
};

