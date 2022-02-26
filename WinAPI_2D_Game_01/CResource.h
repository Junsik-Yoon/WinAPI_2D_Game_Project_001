#pragma once


class CResource
{
private:
	wstring m_strKey; //Ű��
	wstring m_strPath; //���

public:

	void SetKey(const wstring& strKey) { m_strKey = strKey; }
	void SetPath(const wstring& strPath) { m_strPath = strPath; }
	const wstring& GetKey() { return m_strKey; }
	const wstring& GetPath() { return m_strPath; }

public:
	CResource();
	virtual ~CResource(); 
};

