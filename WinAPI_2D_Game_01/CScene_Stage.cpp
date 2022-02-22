#include "pch.h"
#include "CScene_Stage.h"
#include "CObject.h"
#include "CStick.h"
#include "CRStick.h"
#include "CBall.h"
#include "CBackG.h"

bool isFirstEnter = true;

CScene_Stage::CScene_Stage()
{
}

CScene_Stage::~CScene_Stage()
{
}

void CScene_Stage::Enter()
{
	rightPoint = 0;
	leftPoint = 0;
	if (true == isFirstEnter)
	{
		//게임구현

		CObject* pBackGround = new CBackG;
		AddObject(pBackGround,GROUP_TYPE::DEFAULT);

		CObject* pLeftStick = new CStick;
		pLeftStick->SetPos(fPoint(100, WINSIZEY / 2));
		pLeftStick->SetScale(fPoint(5, 300));
		AddObject(pLeftStick, GROUP_TYPE::DEFAULT);

		CObject* pRightStick = new CRStick;
		pRightStick->SetPos(fPoint(WINSIZEX - 100, WINSIZEY / 2));
		pRightStick->SetScale(fPoint(5, 300));
		AddObject(pRightStick, GROUP_TYPE::DEFAULT);

		CObject* pBall = new CBall;
		pBall->SetPos(fPoint(WINSIZEX / 2, WINSIZEY / 2));
		pBall->SetScale(fPoint(50, 50));
		AddObject(pBall, GROUP_TYPE::DEFAULT);

		isFirstEnter = false;
	}

	
}

void CScene_Stage::Exit()
{





}


