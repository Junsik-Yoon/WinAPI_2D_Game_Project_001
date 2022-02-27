#include "pch.h"
#include "CCore.h"

#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CSceneManager.h"
#include "CPathManager.h"
#include "CCollisionManager.h"

CCore::CCore()
	:m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
	, m_hBit(0)
	,m_memDC(0)
	, m_arrBrush{}
	, m_arrPen{}
{

}
CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);
	DeleteDC(m_memDC);
	DeleteObject(m_hBit);

	for (int i = 0; i < (UINT)PEN_TYPE::END; ++i)
	{
		DeleteObject(m_arrPen[i]);
	}
}
int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	CPathManager::GetInst()->init();
	CTimeManager::GetInst()->init();
	CKeyManager::GetInst()->init();
	CSceneManager::GetInst()->init();
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;
	//해상도에 맞게 윈도우 크기 조정	
	RECT rt = { 0,0,m_ptResolution.x,m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);

	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);

	//자주 사용할 펜 브러쉬 생성
	CreateBrushPen();
	return S_OK;//init실패체크용
}


void CCore::progress()
{
	CTimeManager::GetInst()->update();
	CKeyManager::GetInst()->update();
	CSceneManager::GetInst()->update();
	CCollisionManager::GetInst()->update();
	
	//=========
	//Rendering
	//=========
	//화면 clear
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	//
	CSceneManager::GetInst()->render(m_memDC);

	//복붙
	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);

	CTimeManager::GetInst()->render();
}

void CCore::CreateBrushPen()
{
	//hollow brush
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	
	//red blue green pen
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}







