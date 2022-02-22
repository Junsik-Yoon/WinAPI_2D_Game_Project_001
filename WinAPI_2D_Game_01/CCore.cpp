#include "pch.h"
#include "CCore.h"
#include "CGameObject.h"
#include "CScene.h"

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
	CSceneManager::getInst()->update();
	//게임의 정보를 갱신
	
//	if (KEYDOWN(VK_SPACE)) //씬전환예시
	//	sceneChange = true; //불타입

}

void CCore::render()
{
	//게임의 정보를 토대로 그려주는 작업
	Rectangle(m_hMemDC, -1 ,- 1, WINSIZEX + 1, WINSIZEY + 1);


	CSceneManager::getInst()->render(m_hMemDC);


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
	CSceneManager::getInst()->init();

	m_hDC = GetDC(hWnd);
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	//CGameObject* obj1 = new CGameObject;

	
}




