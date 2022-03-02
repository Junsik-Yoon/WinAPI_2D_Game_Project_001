#pragma once

class CCore
{
public:
	SINGLETON(CCore);
public:
	void init();
	void update();
	void render();

	HDC GetMainDC() { return m_hDC; }

private:
	HDC		m_hDC;		//윈도우DC
	HDC		m_hMemDC;	//메모리DC
	HBITMAP	m_hBMP;		//메모리비트맵

	//GDI
	HPEN m_arrPen[(UINT)TYPE_PEN::SIZE];
	HBRUSH m_arrBrush[(UINT)TYPE_BRUSH::SIZE];
public:

	void CreateBrushPen();
	HPEN GetPen(TYPE_PEN type);
	HBRUSH GetBrush(TYPE_BRUSH type);

};

