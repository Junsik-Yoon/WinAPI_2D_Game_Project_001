#pragma once
class CPathManager
{
	SINGLETON(CPathManager)
private:
	const static int MAXSIZE_PATH = 255;
	wchar_t m_szContentPath[MAXSIZE_PATH];
public:
	void init();

	const wchar_t* GetContentPath() { return m_szContentPath; }
	
};

