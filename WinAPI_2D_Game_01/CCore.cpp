#include "pch.h"
#include "CCore.h"
#include "CObject.h"

int leftPoint = 0;//���ʽ���
int rightPoint = 0;//�����ʽ���

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
	
	//������ ������ ���� �׷��ִ� �۾�
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);//����
		
	CSceneManager::getInst()->render(m_hMemDC);


	WCHAR exitMessage[30];
	if (leftPoint >= 5 || rightPoint >= 5)
	{		
		swprintf_s(exitMessage, L"������ ����Ǿ����ϴ� ESC�� ���� �������ּ���");
		TextOutW(m_hMemDC, WINSIZEX/2-140,WINSIZEY/2, exitMessage, 26);
	}

	//fps�� ǥ��
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%d", CTimeManager::getInst()->GetFPS());//FPSǥ�� �����̴����� ����
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
	CSceneManager::getInst()->init();

	m_hDC = GetDC(hWnd);
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

}




