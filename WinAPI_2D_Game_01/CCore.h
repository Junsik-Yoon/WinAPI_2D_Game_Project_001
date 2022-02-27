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

	//자주 사용하는 GDI Object
	HBRUSH m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN m_arrPen[(UINT)PEN_TYPE::END];

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();
private:
	void CreateBrushPen();

public:
	POINT GetResolution() { return m_ptResolution; }
	HDC GetMainDC() { return m_hDC; }
	HBRUSH GetBrush(BRUSH_TYPE _eType){ return m_arrBrush[(UINT)_eType]; }
	HPEN GetPen(PEN_TYPE _eType){ return m_arrPen[(UINT)_eType]; }
};

