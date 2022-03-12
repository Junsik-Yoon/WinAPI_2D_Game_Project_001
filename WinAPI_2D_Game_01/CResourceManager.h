#pragma once

class CTexture;
class CSound;

class CResourceManager
{
	SINGLETON(CResourceManager);
private:
	map<wstring, CTexture*> m_mapTex;//Ű��,�ؽ�ó
	map<wstring, CSound*> m_mapSound; //sound ���ҽ��� ���� �ڷᱸ��
	CSound* m_pBGM;
public:
	CTexture* LoadTexture(const wstring& strKey, const wstring& strPath);
	CTexture* FindTexture(const wstring& strKey);
	
	CTexture* CreateTexture(const wstring& strKey, UINT width, UINT height);//��η� ������ �ҷ����� �ʰ� ���� ����
	
	CSound* FindSound(const wstring& strKey);
	CSound* LoadSound(const wstring& strKey, const wstring& strRelativePath);
	
	CSound LoadBGM(const wstring& strKey, const wstring& strRelativePath); // stream����

};

