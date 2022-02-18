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

fPoint g_rectPos;

void CCore::update()
{
	CTimeManager::getInst()->update();
	//게임의 정보를 갱신
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)//눌렸는지 확인
	{
		//왼쪽 눌림
	//	g_rectPos.x -= 1; //*가중치; -> timeManager를 만들어서 똑같이움직이도록
		//거리/시간 -> 속도
		g_rectPos.x -= 300 * CTimeManager::getInst()->getDT();
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)//눌렸는지 확인
	{
		//오른쪽 눌림
		g_rectPos.x += 300 * CTimeManager::getInst()->getDT();
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)//눌렸는지 확인
	{
		//위 눌림
		g_rectPos.y -= 300 * CTimeManager::getInst()->getDT();
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)//눌렸는지 확인
	{
		//아래 눌림
		g_rectPos.y += 300 * CTimeManager::getInst()->getDT();
	}
	
	//fps를 표현
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hDC, WINSIZEX - 50, 10, strFPS,5);
	//SetWindowTextW(hWnd, strFPS);
}

void CCore::render()
{
	//게임의 정보를 토대로 그려주는 작업
	Rectangle(m_hMemDC, -1 ,- 1, WINSIZEX + 1, WINSIZEY + 1);
	Rectangle(m_hMemDC, g_rectPos.x, g_rectPos.y, g_rectPos.x+100, g_rectPos.y+100);

	//memDC 그린 복사본을 원본 DC에 그리는 작업
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
}
void CCore::init()
{
	//Core의 초기화
	CTimeManager::getInst()->init();

	m_hDC = GetDC(hWnd);
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	g_rectPos.x = 300;
	g_rectPos.y = 300;
}




