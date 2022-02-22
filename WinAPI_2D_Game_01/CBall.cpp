#include "pch.h"
#include "CBall.h"
#include "CRStick.h"
#include "CStick.h"
#include "CScene.h"
#include "CScene_Stage.h"

#define BLEFT vPos.x - GetScale().x/2
#define BRIGHT vPos.x + GetScale().x/2
#define BUP vPos.y - GetScale().y/2
#define BDOWN vPos.y + GetScale().y/2
enum class DIREC { RUP, RDOWN, LDOWN, LUP, STILL };
DIREC drc; //방향
bool isFirstTime = true;


CBall::CBall()
{
}

CBall::~CBall()
{
}

void CBall::update()
{
	fPoint vPos=GetPos();


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
	else if ((vLPos.x - vLScale.x / 2 <= BLEFT) && (vLPos.x + vLScale.x / 2 >= BLEFT) && vPos.y > vLPos.y - vLScale.y / 2 && vPos.y < vLPos.y + vLScale.y / 2)
	{
		if (drc == DIREC::LDOWN)
			drc = DIREC::RDOWN;
		else if (drc == DIREC::LUP)
			drc = DIREC::RUP;
		if (vLScale.y > 20)//줄어들 수 있는 사이즈 20으로 제한
			vLScale.y -= 10;
		//테스트해보니 난이도가 쉬워 게임이 안끝나서 공이 막대에 맞을때마다 사이즈가 줄도록 기능추가
	}
	//공이 오른쪽막대에 닿은 상황
	else if ((vRPos.x + vRScale.x / 2 >= BRIGHT) && (vRPos.x - vRScale.x / 2 <= BRIGHT) && vPos.y > vRPos.y - vRScale.y / 2 && vPos.y < vRPos.y + vRScale.y / 2)
	{
		if (drc == DIREC::RDOWN)
			drc = DIREC::LDOWN;
		else if (drc == DIREC::RUP)
			drc = DIREC::LUP;
		if (vRScale.y > 20)
			vRScale.y -= 10;
	}
	//공이 천장에 닿은 상황
	else if (vPos.y <= 0) //공의 y축중심이 공사이즈의절반y좌표와 같다면(천장에닿음)
	{
		if (drc == DIREC::LUP)
			drc = DIREC::LDOWN;
		else if (drc == DIREC::RUP)
			drc = DIREC::RDOWN;

	}
	//공이 바닥에 닿은 상황
	else if (vPos.y >= WINSIZEY - GetScale().y / 2)//공의 y축중심이 y해상도사이즈에서 공사이절반사이즈를 뺀 값과 같다면(바닥에닿음)
	{
		if (drc == DIREC::RDOWN)
			drc = DIREC::RUP;
		else if (drc == DIREC::LDOWN)
			drc = DIREC::LUP;
	}
	//공이 왼쪽을 통과한 상황
	else if (vPos.x <= 0 - GetScale().x) //공의 x축이 공의사이즈만큼 0에서 -로 넘어갔을 때
	{
		++rightPoint;
		vPos.x = WINSIZEX / 2;
		vPos.y = WINSIZEY / 2;
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
	else if (vPos.x >= WINSIZEX + GetScale().y)
	{
		++leftPoint;
		vPos.x = WINSIZEX / 2;
		vPos.y = WINSIZEY / 2;
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
		vPos.x += BSPEED * DT;
		vPos.y += BSPEED * DT;
		break;
	case DIREC::RUP:
		vPos.x += BSPEED * DT;
		vPos.y -= BSPEED * DT;
		break;
	case DIREC::LDOWN:
		vPos.x -= BSPEED * DT;
		vPos.y += BSPEED * DT;
		break;
	case DIREC::LUP:
		vPos.x -= BSPEED * DT;
		vPos.y -= BSPEED * DT;
		break;
	default:
		break;
	}


	SetPos(vPos);
	
}

void CBall::render(HDC hDC)
{
	Ellipse(hDC, 
		GetPos().x - GetScale().x / 2,
		GetPos().y - GetScale().y / 2,
		GetPos().x + GetScale().x / 2,
		GetPos().y + GetScale().y / 2);
}
