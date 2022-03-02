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
	HDC		m_hDC;		//������DC
	HDC		m_hMemDC;	//�޸�DC
	HBITMAP	m_hBMP;		//�޸𸮺�Ʈ��

	//GDI
	HPEN m_arrPen[(UINT)TYPE_PEN::SIZE];
	HBRUSH m_arrBrush[(UINT)TYPE_BRUSH::SIZE];
public:

	void CreateBrushPen();
	HPEN GetPen(TYPE_PEN type);
	HBRUSH GetBrush(TYPE_BRUSH type);

};

