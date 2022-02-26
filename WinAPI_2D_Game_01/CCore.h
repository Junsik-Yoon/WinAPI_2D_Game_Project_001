#pragma once
class CCore
{
	SINGLETON(CCore)

private:
	HWND m_hWnd; //메인 윈도우 핸들
	POINT m_ptResolution;//메인 윈도우 해상도
	HDC m_hDC;
	HBITMAP m_hBit;
	HDC m_memDC;

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();
private:
	void update();
	void render();
public:
	POINT GetResolution() { return m_ptResolution; }
	HDC GetMainDC() { return m_hDC; }
};

