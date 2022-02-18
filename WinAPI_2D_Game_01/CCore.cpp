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
	//������ ������ ����
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)//���ȴ��� Ȯ��
	{
		//���� ����
	//	g_rectPos.x -= 1; //*����ġ; -> timeManager�� ���� �Ȱ��̿����̵���
		//�Ÿ�/�ð� -> �ӵ�
		g_rectPos.x -= 300 * CTimeManager::getInst()->getDT();
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)//���ȴ��� Ȯ��
	{
		//������ ����
		g_rectPos.x += 300 * CTimeManager::getInst()->getDT();
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)//���ȴ��� Ȯ��
	{
		//�� ����
		g_rectPos.y -= 300 * CTimeManager::getInst()->getDT();
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)//���ȴ��� Ȯ��
	{
		//�Ʒ� ����
		g_rectPos.y += 300 * CTimeManager::getInst()->getDT();
	}
	
	//fps�� ǥ��
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hDC, WINSIZEX - 50, 10, strFPS,5);
	//SetWindowTextW(hWnd, strFPS);
}

void CCore::render()
{
	//������ ������ ���� �׷��ִ� �۾�
	Rectangle(m_hMemDC, -1 ,- 1, WINSIZEX + 1, WINSIZEY + 1);
	Rectangle(m_hMemDC, g_rectPos.x, g_rectPos.y, g_rectPos.x+100, g_rectPos.y+100);

	//memDC �׸� ���纻�� ���� DC�� �׸��� �۾�
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
}
void CCore::init()
{
	//Core�� �ʱ�ȭ
	CTimeManager::getInst()->init();

	m_hDC = GetDC(hWnd);
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	g_rectPos.x = 300;
	g_rectPos.y = 300;
}




