#pragma once

class CCore
{
public:
	SINGLETON(CCore);
public:
	void init();
	void update();
	void render();

	HDC GetMainDC() { return m_hMemDC; }

	void CreateBrushPen();
	HBRUSH GetBrush(TYPE_BRUSH type){ return m_arrBrush[(int)type]; }
	HPEN GetPen(TYPE_PEN type){ return m_arrPen[(int)type]; }

private:
	HDC		m_hDC;		//������DC
	HDC		m_hMemDC;	//�޸�DC
	HBITMAP	m_hBMP;		//�޸𸮺�Ʈ��

	// GDI
	HBRUSH m_arrBrush[(int)TYPE_BRUSH::SIZE];
	HPEN m_arrPen[(int)TYPE_PEN::SIZE];
};

