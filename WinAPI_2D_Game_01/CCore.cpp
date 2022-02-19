#include "pch.h"
#include "CCore.h"

#include "CObject.h"

CObject g_obj;

CCore::CCore()
{

}
CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);
}
int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;
	//해상도에 맞게 윈도우 크기 조정	
	RECT rt = { 0,0,m_ptResolution.x,m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);

	g_obj.m_ptPos = POINT{ m_ptResolution.x,m_ptResolution.y };
	g_obj.m_ptScale = POINT{ 100,100 };

	return S_OK;//init실패체크용
}


void CCore::progress()
{
	update();

	render();
}

void CCore::update()
{

	g_obj.m_ptPos;
}

void CCore::render()
{
	//그리기
	Rectangle(m_hDC, 10, 10, 110, 110);
}




