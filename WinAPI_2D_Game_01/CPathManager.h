#pragma once
class CPathManager
{
	SINGLETON(CPathManager);
private:
	wchar_t m_szContentPath[255];
public:
	void init();
	const wchar_t* GetContentPath() { return m_szContentPath; }//훼손되면 안되므로 const로

};

