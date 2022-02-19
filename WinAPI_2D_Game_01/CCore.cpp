#include "pch.h"
#include "CCore.h"
#include "CObject.h"

#define BSPEED 300//공속도
#define SSPEED 300//막대속도
#define BLEFT vBallPos.x - vBallScale.x/2
#define BRIGHT vBallPos.x + vBallScale.x/2
#define BUP vBallPos.y - vBallScale.y/2
#define BDOWN vBallPos.y + vBallScale.y/2
bool isFirstTime = true;
enum class DIREC { RUP, RDOWN, LDOWN, LUP };
DIREC drc; //방향
int leftPoint = 0;//왼쪽승점
int rightPoint = 0;//오른쪽승점

//DIREC DChange(DIREC* _drc);//반향전환함수

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

	//Player1 위아래
	if (GetAsyncKeyState('W') & 0x8000)//Player1 위
	{
		if (vLSPos.y > leftStick.getScale().y / 2)
		{
			vLSPos.y -= SSPEED * CTimeManager::getInst()->getDT();
		}
	}
	if (GetAsyncKeyState('S') & 0x8000)//Player1 아래
	{
		if (vLSPos.y < WINSIZEY - leftStick.getScale().y / 2)
		{
			vLSPos.y += SSPEED * CTimeManager::getInst()->getDT();
		}
	}

	//player2 위아래
	if (GetAsyncKeyState(VK_UP) & 0x8000)//player2 위
	{
		if (vRSPos.y > rightStick.getScale().y / 2)
		{
			vRSPos.y -= SSPEED * CTimeManager::getInst()->getDT();
		}
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)//player2 아래
	{
		if (vRSPos.y < WINSIZEY - rightStick.getScale().y / 2)
		{
			vRSPos.y += SSPEED * CTimeManager::getInst()->getDT();
		}
	}

	//공
	//공 방향 처음 RDOWN
	if (true == isFirstTime)
	{
		drc = DIREC::LUP;
		isFirstTime = false;
	}
	//공이 왼쪽막대에 닿은 상황
	else if ((vLSPos.x - vLSScale.x / 2 <= BLEFT) && (vLSPos.x + vLSScale.x / 2 >= BLEFT) && vBallPos.y > vLSPos.y - vLSScale.y / 2 && vBallPos.y < vLSPos.y + vLSScale.y / 2)
	{
		if (drc == DIREC::LDOWN)
			drc = DIREC::RDOWN;
		else if (drc == DIREC::LUP)
			drc = DIREC::RUP;
	}
	//공이 오른쪽막대에 닿은 상황
	else if ((vRSPos.x + vRSScale.x / 2 >= BRIGHT) && (vRSPos.x - vRSScale.x / 2 <= BRIGHT) && vBallPos.y > vRSPos.y - vRSScale.y / 2 && vBallPos.y < vRSPos.y + vRSScale.y / 2)
	{
		if (drc == DIREC::RDOWN)
			drc = DIREC::LDOWN;
		else if (drc == DIREC::RUP)
			drc = DIREC::LUP;
	}
	//공이 천장에 닿은 상황
	else if (vBallPos.y <= 0) //공의 y축중심이 공사이즈의절반y좌표와 같다면(천장에닿음)
	{
		if (drc == DIREC::LUP)
			drc = DIREC::LDOWN;
		else if (drc == DIREC::RUP)
			drc = DIREC::RDOWN;
	}
	//공이 바닥에 닿은 상황
	else if (vBallPos.y >= WINSIZEY - ball.getScale().y / 2)//공의 y축중심이 y해상도사이즈에서 공사이절반사이즈를 뺀 값과 같다면(바닥에닿음)
	{
		if (drc == DIREC::RDOWN)
			drc = DIREC::RUP;
		else if (drc == DIREC::LDOWN)
			drc = DIREC::LUP;
	}
	//공이 왼쪽을 통과한 상황
	else if (vBallPos.x <= ball.getScale().x) //공의 x축이 공의사이즈만큼 0에서 -로 넘어갔을 때
	{
		++rightPoint;
		//오른쪽승리 점수+=1 -> 공 초기화 오른쪽으로 쏘기
	}
	//공이 오른쪽을 통과한 상황
	else if (vBallPos.x >= WINSIZEX + ball.getScale().y)
	{
		++leftPoint;
		//왼쪽승리 점수+=1 -> 공 초기화 왼쪽으로 쏘기
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
	}

	leftStick.setPos(vLSPos);
	rightStick.setPos(vRSPos);
	ball.setPos(vBallPos);

	//fps를 표현
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hDC, WINSIZEX - 50, 10, strFPS,5);
	//SetWindowTextW(hWnd, strFPS);
}

void CCore::render()
{
	
	//게임의 정보를 토대로 그려주는 작업
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);
	Rectangle(m_hMemDC, vLSPos.x - vLSScale.x / 2, vLSPos.y - vLSScale.y / 2, vLSPos.x + vLSScale.x / 2, vLSPos.y + vLSScale.y / 2);
	Rectangle(m_hMemDC, vRSPos.x - vRSScale.x / 2, vRSPos.y - vRSScale.y / 2, vRSPos.x + vRSScale.x / 2, vRSPos.y + vRSScale.y / 2);
	Ellipse(m_hMemDC, vBallPos.x - vBallScale.x / 2, vBallPos.y - vBallScale.y / 2, vBallPos.x + vBallScale.x / 2, vBallPos.y + vBallScale.y / 2);

	//Rectangle(m_hMemDC, -1 ,- 1, WINSIZEX + 1, WINSIZEY + 1);
	//Rectangle(m_hMemDC, leftStick.getPos().x - leftStick.getScale().x / 2, leftStick.getPos().y - leftStick.getScale().y / 2, leftStick.getPos().x + leftStick.getScale().x / 2, leftStick.getPos().y + leftStick.getScale().y / 2);
	//Rectangle(m_hMemDC, rightStick.getPos().x - rightStick.getScale().x / 2, rightStick.getPos().y - rightStick.getScale().y / 2, rightStick.getPos().x + rightStick.getScale().x / 2, rightStick.getPos().y + rightStick.getScale().y / 2);
	//Ellipse(m_hMemDC, ball.getPos().x - ball.getScale().x / 2, ball.getPos().y - ball.getScale().y / 2, ball.getPos().x + ball.getScale().x / 2, ball.getPos().y + ball.getScale().y / 2);

	
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



	leftStick.setPos(vLSPos);
	rightStick.setPos(vRSPos);
	ball.setPos(vBallPos);
	leftStick.setScale(vLSScale);
	rightStick.setScale(vRSScale);
	ball.setScale(vBallScale);
}

//DIREC DChange(DIREC* _drc)
//{
//	if (_drc == DIREC::LDOWN)
//	{
//		_drc = DIREC::RUP
//	}
//	return *_drc;
//}




