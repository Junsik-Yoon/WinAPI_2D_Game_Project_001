#pragma once



class CRes
{
private:
	wstring m_strKey; //Ű�� / ����ID
	wstring m_strRelativePath;//���ҽ� �����

public:
	void SetKey(const wstring& _strKey) { m_strKey = _strKey; }
	void SetRelativePath(const wstring& _strRelativePath) { m_strRelativePath = _strRelativePath; }

	const wstring& GetKey() { return m_strKey; }
	const wstring& GetRelativePath() { return m_strRelativePath; }

public:
	CRes();
	~CRes();

};

