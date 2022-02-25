#pragma once
class CPathManager
{
	SINGLETON(CPathManager)
private:
	const static int MAXSIZE_PATH = 255;
	WCHAR m_szContentPath[MAXSIZE_PATH];
public:
	void init();


};

