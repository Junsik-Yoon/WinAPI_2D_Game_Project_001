#pragma once

class CCore
{
public:
	SINGLETON(CCore);
public:
	void init();
	void update();
	void render();

private:
	HDC		m_hDC;		//윈도우DC
	HDC		m_hMemDC;	//메모리DC
	HBITMAP	m_hBMP;		//메모리비트맵
};

