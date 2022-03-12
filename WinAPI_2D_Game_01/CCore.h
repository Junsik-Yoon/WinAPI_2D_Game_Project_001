#pragma once

class CTexture;

class CCore
{
public:
	SINGLETON(CCore);

private:
	HDC		m_hDC;		//윈도우DC

	CTexture* m_pMemTex;

	//HDC		m_hMemDC;	//메모리DC
	//HBITMAP	m_hBMP;		//메모리비트맵

	// GDI
	HBRUSH m_arrBrush[(int)TYPE_BRUSH::SIZE];
	HPEN m_arrPen[(int)TYPE_PEN::SIZE];
public:
	void init();
	void update();
	void render();

	HDC GetMainDC() { return m_hDC; }

	void CreateBrushPen();
	HBRUSH GetBrush(TYPE_BRUSH type){ return m_arrBrush[(int)type]; }
	HPEN GetPen(TYPE_PEN type){ return m_arrPen[(int)type]; }


};

