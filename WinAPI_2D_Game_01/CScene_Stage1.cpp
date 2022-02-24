#include "pch.h"
#include "CScene_Stage1.h"
#include "CGameObject.h"

#include "CPlayer.h"
#include "CMonster.h"
#include "CLand.h"

#define ONLAND pLand->GetPos().y - pLand->GetScale().y - pPlayer->GetScale().y
CScene_Stage1::CScene_Stage1()
{
}

CScene_Stage1::~CScene_Stage1()
{
}

void CScene_Stage1::Enter()
{
	CGameObject* pLand = new CLand;
	pLand->SetPos(fVec2(WINSIZEX / 2, WINSIZEY - 50));
	AddObject(pLand, GROUP_GAMEOBJ::DEFAULT);

	//Player 추가
	CGameObject* pPlayer = new CPlayer;
	pPlayer->SetPos(fVec2(300, ONLAND));
	AddObject(pPlayer, GROUP_GAMEOBJ::PLAYER);

	//Monster 추가
	CMonster* pMonster = new CMonster;
	pMonster->SetPos(fVec2(1200, 350));
	pMonster->SetCenterPos(pMonster->GetPos());
	AddObject(pMonster, GROUP_GAMEOBJ::MONSTER);
}

void CScene_Stage1::Exit()
{
	ClearObject();
}
