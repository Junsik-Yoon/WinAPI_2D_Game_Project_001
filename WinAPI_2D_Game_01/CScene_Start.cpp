#include "pch.h"
#include "CScene_Start.h"
#include "CGameObject.h"
#include "CPlayer.h"
#include "CMonster.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{

	
	//Player 추가
	CGameObject* pPlayer = new CPlayer;
	pPlayer->SetPos(fVec2(300, 500));
	pPlayer->SetScale(fVec2(50, 50));
	AddObject(pPlayer, GROUP_GAMEOBJ::PLAYER);

	//Monster 추가
	CMonster* pMonster = new CMonster;
	pMonster->SetPos(fVec2(1000, 300));
	pMonster->SetCenterPos(pMonster->GetPos());
	AddObject(pMonster, GROUP_GAMEOBJ::MONSTER);
}

void CScene_Start::Exit()
{
	ClearObject();
}
