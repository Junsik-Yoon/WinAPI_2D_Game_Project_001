#include "pch.h"
#include "CCore.h"
#include "CObject.h"

int leftPoint = 0;//왼쪽승점
int rightPoint = 0;//오른쪽승점

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
	CKeyManager::getInst()->update();
	CTimeManager::getInst()->update();
	CSceneManager::getInst()->update();
}

void CCore::render()
{
	
	//게임의 정보를 토대로 그려주는 작업
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);//백지
		
	CSceneManager::getInst()->render(m_hMemDC);


	WCHAR exitMessage[30];
	if (leftPoint >= 5 || rightPoint >= 5)
	{		
		swprintf_s(exitMessage, L"게임이 종료되었습니다 ESC를 눌러 종료해주세요");
		TextOutW(m_hMemDC, WINSIZEX/2-140,WINSIZEY/2, exitMessage, 26);
	}

	//fps를 표현
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%d", CTimeManager::getInst()->GetFPS());//FPS표시 깜빡이는현상 수정
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
	CSceneManager::getInst()->init();

	m_hDC = GetDC(hWnd);
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

}




