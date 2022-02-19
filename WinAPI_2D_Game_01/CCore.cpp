#include "pch.h"
#include "CCore.h"
#include "CObject.h"

CCore::CCore()
{
}
CCore::~CCore()
{
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);
}

fPoint vLSPos = { 100,WINSIZEY / 2 };
fPoint vRSPos = { WINSIZEX - 100,WINSIZEY / 2 };
fPoint vBallPos = { WINSIZEX / 2,WINSIZEY / 2 };
fPoint vLSScale = { 50,300 };
fPoint vRSScale = { 50,300 };
fPoint vBallScale = { 50,50 };
	
CObject leftStick, rightStick, ball;

void CCore::update()
{
	CTimeManager::getInst()->update();
	//Player1 ���Ʒ�

	vLSPos = leftStick.getPos();
	vRSPos = rightStick.getPos();
	if (GetAsyncKeyState('W') & 0x8000)//Player1 ��
	{
		vLSPos.y -= 300 * CTimeManager::getInst()->getDT();
	}
	if (GetAsyncKeyState('S') & 0x8000)//Player1 �Ʒ�
	{
		vLSPos.y += 300 * CTimeManager::getInst()->getDT();
	}

	//player2 ���Ʒ�
	if (GetAsyncKeyState(VK_UP) & 0x8000)//player2 ��
	{
		vRSPos.y -= 300 * CTimeManager::getInst()->getDT();
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)//player2 �Ʒ�
	{
		vRSPos.y += 300 * CTimeManager::getInst()->getDT();
	}
	leftStick.setPos(vLSPos);
	rightStick.setPos(vRSPos);

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
	Rectangle(m_hMemDC, leftStick.getPos().x - leftStick.getScale().x / 2, leftStick.getPos().y - leftStick.getScale().y / 2, leftStick.getPos().x + leftStick.getScale().x / 2, leftStick.getPos().y + leftStick.getScale().y / 2);
	Rectangle(m_hMemDC, rightStick.getPos().x - rightStick.getScale().x / 2, rightStick.getPos().y - rightStick.getScale().y / 2, rightStick.getPos().x + rightStick.getScale().x / 2, rightStick.getPos().y + rightStick.getScale().y / 2);
	Ellipse(m_hMemDC, ball.getPos().x - ball.getScale().x / 2, ball.getPos().y - ball.getScale().y / 2, ball.getPos().x + ball.getScale().x / 2, ball.getPos().y + ball.getScale().y / 2);

	
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



	leftStick.setPos(vLSPos);
	rightStick.setPos(vRSPos);
	ball.setPos(vBallPos);
	leftStick.setScale(vLSScale);
	rightStick.setScale(vRSScale);
	ball.setScale(vBallScale);
}




