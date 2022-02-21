#include "pch.h"
#include "CCore.h"

CCore::CCore()
{
}
CCore::~CCore()
{
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);
}

void CCore::update()
{
	CTimeManager::getInst()->update();
	CKeyManager::getInst()->update();
	//게임의 정보를 갱신
	if (CKeyManager::getInst()->GetButton(VK_LEFT))
	{

	}
	if (CKeyManager::getInst()->GetButton(VK_RIGHT))//눌렸는지 확인
	{

	}
	if (CKeyManager::getInst()->GetButton(VK_UP))//눌렸는지 확인
	{

	}
	if (CKeyManager::getInst()->GetButton(VK_DOWN))//눌렸는지 확인
	{

	}

}

void CCore::render()
{
	//게임의 정보를 토대로 그려주는 작업
	Rectangle(m_hMemDC, -1 ,- 1, WINSIZEX + 1, WINSIZEY + 1);




	//fps를 표현
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);
	//SetWindowTextW(hWnd, strFPS);
	
	//memDC 그린 복사본을 원본 DC에 그리는 작업
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
}
void CCore::init()
{
	//Core의 초기화
	CTimeManager::getInst()->init();
	CKeyManager::getInst()->init();

	m_hDC = GetDC(hWnd);
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

}




