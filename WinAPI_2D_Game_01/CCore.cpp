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
	//������ ������ ����
	if (CKeyManager::getInst()->GetButton(VK_LEFT))
	{

	}
	if (CKeyManager::getInst()->GetButton(VK_RIGHT))//���ȴ��� Ȯ��
	{

	}
	if (CKeyManager::getInst()->GetButton(VK_UP))//���ȴ��� Ȯ��
	{

	}
	if (CKeyManager::getInst()->GetButton(VK_DOWN))//���ȴ��� Ȯ��
	{

	}

}

void CCore::render()
{
	//������ ������ ���� �׷��ִ� �۾�
	Rectangle(m_hMemDC, -1 ,- 1, WINSIZEX + 1, WINSIZEY + 1);




	//fps�� ǥ��
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);
	//SetWindowTextW(hWnd, strFPS);
	
	//memDC �׸� ���纻�� ���� DC�� �׸��� �۾�
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
}
void CCore::init()
{
	//Core�� �ʱ�ȭ
	CTimeManager::getInst()->init();
	CKeyManager::getInst()->init();

	m_hDC = GetDC(hWnd);
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

}




