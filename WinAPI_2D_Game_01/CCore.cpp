#include "pch.h"
#include "CCore.h"
#include "CObject.h"

#include <stdlib.h>
#include <time.h>

#define BSPEED 600//공속도
#define SSPEED 300//막대속도
#define BLEFT vBallPos.x - vBallScale.x/2
#define BRIGHT vBallPos.x + vBallScale.x/2
bool isFirstTime = true;
enum class DIREC { RUP, RDOWN, LDOWN, LUP, STILL };
DIREC drc; //방향
int leftPoint = 0;//왼쪽승점
int rightPoint = 0;//오른쪽승점

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

	//Player1 위아래
	if (GetAsyncKeyState('W') & 0x8000)//Player1 위
	{
		if (vLSPos.y > vLSScale.y / 2)
		{
			vLSPos.y -= SSPEED * CTimeManager::getInst()->getDT();
		}
	}
	if (GetAsyncKeyState('S') & 0x8000)//Player1 아래
	{
		if (vLSPos.y < WINSIZEY - vLSScale.y / 2)
		{
			vLSPos.y += SSPEED * CTimeManager::getInst()->getDT();
		}
	}

	//player2 위아래
	if (GetAsyncKeyState(VK_UP) & 0x8000)//player2 위
	{
		if (vRSPos.y > vRSScale.y / 2)
		{
			vRSPos.y -= SSPEED * CTimeManager::getInst()->getDT();
		}
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)//player2 아래
	{
		if (vRSPos.y < WINSIZEY - vRSScale.y / 2)
		{
			vRSPos.y += SSPEED * CTimeManager::getInst()->getDT();
		}
	}

	//게임종료
	if(GetAsyncKeyState(VK_ESCAPE)&0x8000) //esc입력시 게임 종료
		PostQuitMessage(0);

	//공
	//공 방향 처음 랜덤
	if (true == isFirstTime)
	{
		switch (rando())//공 방향 랜덤
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
	//공이 왼쪽막대에 닿은 상황
	else if ((vLSPos.x - vLSScale.x / 2 <= BLEFT) && (vLSPos.x + vLSScale.x / 2 >= BLEFT) && vBallPos.y > vLSPos.y - vLSScale.y / 2 && vBallPos.y < vLSPos.y + vLSScale.y / 2)
	{
		if (drc == DIREC::LDOWN)
			drc = DIREC::RDOWN;
		else if (drc == DIREC::LUP)
			drc = DIREC::RUP;
		if (vLSScale.y > 20)//줄어들 수 있는 사이즈 20으로 제한
			vLSScale.y -= 10;
		//테스트해보니 난이도가 쉬워 게임이 안끝나서 공이 막대에 맞을때마다 사이즈가 줄도록 기능추가
	}
	//공이 오른쪽막대에 닿은 상황
	else if ((vRSPos.x + vRSScale.x / 2 >= BRIGHT) && (vRSPos.x - vRSScale.x / 2 <= BRIGHT) && vBallPos.y > vRSPos.y - vRSScale.y / 2 && vBallPos.y < vRSPos.y + vRSScale.y / 2)
	{
		if (drc == DIREC::RDOWN)
			drc = DIREC::LDOWN;
		else if (drc == DIREC::RUP)
			drc = DIREC::LUP;
		if(vRSScale.y>20)
			vRSScale.y -= 10;
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
	else if (vBallPos.x <= 0-ball.getScale().x) //공의 x축이 공의사이즈만큼 0에서 -로 넘어갔을 때
	{
		++rightPoint;
		vBallPos.x = WINSIZEX / 2;
		vBallPos.y = WINSIZEY / 2;
		switch (rando())//공 방향 랜덤
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
			MessageBoxW(hWnd, L"player2가 승리하였습니다", L"player2승리", MB_OK);
			drc = DIREC::STILL;
		}
	}
	//공이 오른쪽을 통과한 상황
	else if (vBallPos.x >= WINSIZEX + ball.getScale().y)
	{
		++leftPoint;
		vBallPos.x = WINSIZEX / 2;
		vBallPos.y = WINSIZEY / 2;
		switch (rando())//공 방향 랜덤
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
			MessageBoxW(hWnd, L"player1가 승리하였습니다", L"player1승리", MB_OK);
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
	
	//게임의 정보를 토대로 그려주는 작업
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);//백지
	
	//게임스코어
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
	
	//도형
	Rectangle(m_hMemDC, (WINSIZEX / 2) - 1, 0, (WINSIZEX / 2) + 1, WINSIZEY);
	Rectangle(m_hMemDC, vLSPos.x - vLSScale.x / 2, vLSPos.y - vLSScale.y / 2, vLSPos.x + vLSScale.x / 2, vLSPos.y + vLSScale.y / 2);
	Rectangle(m_hMemDC, vRSPos.x - vRSScale.x / 2, vRSPos.y - vRSScale.y / 2, vRSPos.x + vRSScale.x / 2, vRSPos.y + vRSScale.y / 2);
	Ellipse(m_hMemDC, vBallPos.x - vBallScale.x / 2, vBallPos.y - vBallScale.y / 2, vBallPos.x + vBallScale.x / 2, vBallPos.y + vBallScale.y / 2);

	WCHAR exitMessage[18];
	if (leftPoint >= 5 || rightPoint >= 5)
	{		
		swprintf_s(exitMessage, L"종료하시려면 esc를 눌러주세요");//FPS표시 깜빡이는현상 수정
		TextOutW(m_hMemDC, WINSIZEX/2-140,WINSIZEY/2, exitMessage, 17);
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




