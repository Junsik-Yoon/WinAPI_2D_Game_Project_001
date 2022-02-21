#include "pch.h"
#include "CCore.h"
#include "CObject.h"

#include <stdlib.h>
#include <time.h>

#define BSPEED 600//���ӵ�
#define SSPEED 300//����ӵ�
#define BLEFT vBallPos.x - vBallScale.x/2
#define BRIGHT vBallPos.x + vBallScale.x/2
bool isFirstTime = true;
enum class DIREC { RUP, RDOWN, LDOWN, LUP, STILL };
DIREC drc; //����
int leftPoint = 0;//���ʽ���
int rightPoint = 0;//�����ʽ���

int rando()
{
	srand(time(NULL));
	return (rand() % 4);
}


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
fPoint vLSScale = { 5,300 };
fPoint vRSScale = { 5,300 };
fPoint vBallScale = { 50,50 };
	
CObject leftStick, rightStick, ball;

void CCore::update()
{
	CTimeManager::getInst()->update();

	vLSPos = leftStick.getPos();
	vRSPos = rightStick.getPos();
	vBallPos = ball.getPos();

	//Player1 ���Ʒ�
	if (GetAsyncKeyState('W') & 0x8000)//Player1 ��
	{
		if (vLSPos.y > vLSScale.y / 2)
		{
			vLSPos.y -= SSPEED * CTimeManager::getInst()->getDT();
		}
	}
	if (GetAsyncKeyState('S') & 0x8000)//Player1 �Ʒ�
	{
		if (vLSPos.y < WINSIZEY - vLSScale.y / 2)
		{
			vLSPos.y += SSPEED * CTimeManager::getInst()->getDT();
		}
	}

	//player2 ���Ʒ�
	if (GetAsyncKeyState(VK_UP) & 0x8000)//player2 ��
	{
		if (vRSPos.y > vRSScale.y / 2)
		{
			vRSPos.y -= SSPEED * CTimeManager::getInst()->getDT();
		}
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)//player2 �Ʒ�
	{
		if (vRSPos.y < WINSIZEY - vRSScale.y / 2)
		{
			vRSPos.y += SSPEED * CTimeManager::getInst()->getDT();
		}
	}

	//��������
	if(GetAsyncKeyState(VK_ESCAPE)&0x8000) //esc�Է½� ���� ����
		PostQuitMessage(0);

	//��
	//�� ���� ó�� ����
	if (true == isFirstTime)
	{
		switch (rando())//�� ���� ����
		{
		case 0: drc = DIREC::RDOWN;
			break;
		case 1: drc = DIREC::LDOWN;
			break;
		case 2: drc = DIREC::RUP;
			break;
		case 3: drc = DIREC::LUP;
			break;
		}
		isFirstTime = false;
	}
	//���� ���ʸ��뿡 ���� ��Ȳ
	else if ((vLSPos.x - vLSScale.x / 2 <= BLEFT) && (vLSPos.x + vLSScale.x / 2 >= BLEFT) && vBallPos.y > vLSPos.y - vLSScale.y / 2 && vBallPos.y < vLSPos.y + vLSScale.y / 2)
	{
		if (drc == DIREC::LDOWN)
			drc = DIREC::RDOWN;
		else if (drc == DIREC::LUP)
			drc = DIREC::RUP;
		if (vLSScale.y > 20)//�پ�� �� �ִ� ������ 20���� ����
			vLSScale.y -= 10;
		//�׽�Ʈ�غ��� ���̵��� ���� ������ �ȳ����� ���� ���뿡 ���������� ����� �ٵ��� ����߰�
	}
	//���� �����ʸ��뿡 ���� ��Ȳ
	else if ((vRSPos.x + vRSScale.x / 2 >= BRIGHT) && (vRSPos.x - vRSScale.x / 2 <= BRIGHT) && vBallPos.y > vRSPos.y - vRSScale.y / 2 && vBallPos.y < vRSPos.y + vRSScale.y / 2)
	{
		if (drc == DIREC::RDOWN)
			drc = DIREC::LDOWN;
		else if (drc == DIREC::RUP)
			drc = DIREC::LUP;
		if(vRSScale.y>20)
			vRSScale.y -= 10;
	}
	//���� õ�忡 ���� ��Ȳ
	else if (vBallPos.y <= 0) //���� y���߽��� ��������������y��ǥ�� ���ٸ�(õ�忡����)
	{
		if (drc == DIREC::LUP)
			drc = DIREC::LDOWN;
		else if (drc == DIREC::RUP)
			drc = DIREC::RDOWN;

	}
	//���� �ٴڿ� ���� ��Ȳ
	else if (vBallPos.y >= WINSIZEY - ball.getScale().y / 2)//���� y���߽��� y�ػ󵵻������ ���������ݻ���� �� ���� ���ٸ�(�ٴڿ�����)
	{
		if (drc == DIREC::RDOWN)
			drc = DIREC::RUP;
		else if (drc == DIREC::LDOWN)
			drc = DIREC::LUP;
	}
	//���� ������ ����� ��Ȳ
	else if (vBallPos.x <= 0-ball.getScale().x) //���� x���� ���ǻ����ŭ 0���� -�� �Ѿ�� ��
	{
		++rightPoint;
		vBallPos.x = WINSIZEX / 2;
		vBallPos.y = WINSIZEY / 2;
		switch (rando())//�� ���� ����
		{
		case 0: drc = DIREC::RDOWN;
			break;
		case 1: drc = DIREC::LDOWN;
			break;
		case 2: drc = DIREC::RUP;
			break;
		case 3: drc = DIREC::LUP;
			break;
		}
		if (5 == rightPoint)
		{
			MessageBoxW(hWnd, L"player2�� �¸��Ͽ����ϴ�", L"player2�¸�", MB_OK);
			drc = DIREC::STILL;
		}
	}
	//���� �������� ����� ��Ȳ
	else if (vBallPos.x >= WINSIZEX + ball.getScale().y)
	{
		++leftPoint;
		vBallPos.x = WINSIZEX / 2;
		vBallPos.y = WINSIZEY / 2;
		switch (rando())//�� ���� ����
		{
		case 0: drc = DIREC::RDOWN;
			break;
		case 1: drc = DIREC::LDOWN;
			break;
		case 2: drc = DIREC::RUP;
			break;
		case 3: drc = DIREC::LUP;
			break;
		}
		if (5 == leftPoint)
		{
			MessageBoxW(hWnd, L"player1�� �¸��Ͽ����ϴ�", L"player1�¸�", MB_OK);
			drc = DIREC::STILL;
		}
	}



	switch (drc)
	{
	case DIREC::RDOWN:
		vBallPos.x += BSPEED * CTimeManager::getInst()->getDT();
		vBallPos.y += BSPEED * CTimeManager::getInst()->getDT();
		break;
	case DIREC::RUP:
		vBallPos.x += BSPEED * CTimeManager::getInst()->getDT();
		vBallPos.y -= BSPEED * CTimeManager::getInst()->getDT();
		break;
	case DIREC::LDOWN:
		vBallPos.x -= BSPEED * CTimeManager::getInst()->getDT();
		vBallPos.y += BSPEED * CTimeManager::getInst()->getDT();
		break;
	case DIREC::LUP:
		vBallPos.x -= BSPEED * CTimeManager::getInst()->getDT();
		vBallPos.y -= BSPEED * CTimeManager::getInst()->getDT();
		break;
	default:
		break;
	}

	leftStick.setPos(vLSPos);
	rightStick.setPos(vRSPos);
	ball.setPos(vBallPos);

}

void CCore::render()
{
	
	//������ ������ ���� �׷��ִ� �۾�
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);//����
	
	//���ӽ��ھ�
	for (int i = 0; i < 5; ++i)
	{
		if (i+1 <= leftPoint)
			Rectangle(m_hMemDC, 30+i*5, 30, 32+i*5, 60);
	}
	for (int i = 0; i < 5; ++i)
	{
		if (i+1 <= rightPoint)
			Rectangle(m_hMemDC, 1100+i*5, 30, 1102+i*5, 60);
	}
	
	//����
	Rectangle(m_hMemDC, (WINSIZEX / 2) - 1, 0, (WINSIZEX / 2) + 1, WINSIZEY);
	Rectangle(m_hMemDC, vLSPos.x - vLSScale.x / 2, vLSPos.y - vLSScale.y / 2, vLSPos.x + vLSScale.x / 2, vLSPos.y + vLSScale.y / 2);
	Rectangle(m_hMemDC, vRSPos.x - vRSScale.x / 2, vRSPos.y - vRSScale.y / 2, vRSPos.x + vRSScale.x / 2, vRSPos.y + vRSScale.y / 2);
	Ellipse(m_hMemDC, vBallPos.x - vBallScale.x / 2, vBallPos.y - vBallScale.y / 2, vBallPos.x + vBallScale.x / 2, vBallPos.y + vBallScale.y / 2);

	WCHAR exitMessage[18];
	if (leftPoint >= 5 || rightPoint >= 5)
	{		
		swprintf_s(exitMessage, L"�����Ͻ÷��� esc�� �����ּ���");//FPSǥ�� �����̴����� ����
		TextOutW(m_hMemDC, WINSIZEX/2-140,WINSIZEY/2, exitMessage, 17);
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




