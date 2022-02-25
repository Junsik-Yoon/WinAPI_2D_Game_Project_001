#pragma once


class CResource
{
private:
	wstring m_strKey; //키값
	wstring m_strPath; //경로

public:

	void SetKey(const wstring& strKey) { m_strKey = strKey; }
	void SetPath(const wstring& strPath) { m_strPath = strPath; }
	const wstring& GetKey() { return m_strKey; }
	const wstring& GetPath() { return m_strPath; }

public:
	CResource();
	virtual ~CResource(); //상속할때 자식의 소멸자가 생성되도록
};

