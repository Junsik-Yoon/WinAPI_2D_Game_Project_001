#include "pch.h"
#include "CScene_Start.h"

#include "CObject.h"

#include "CPlayer.h"
#include "CMonster.h"

#include "CCore.h"

#include "CPathManager.h"
#include "CTexture.h"

#include "CCollisionManager.h"


CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
	
}


void CScene_Start::Enter()
{
	//Player object추가
	CObject* pObj = new CPlayer;//실제로 생성된객체는 플레이어지만 플레이어의 주소를 받은건 부모포인터타입

	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f, 100.f));

	AddObject(pObj, GROUP_TYPE::PLAYER);


	//몬스터 배치
	int iMonCount = 1;
	float fMoveDist = 25.f;
	float fObjScale = 50.f;
	float fTerm = (WINSIZEX - ((fMoveDist + fObjScale / 2.f) * 2)) / iMonCount - 1;
	CMonster* pMonsterObj = nullptr;
	for (int i = 0; i < iMonCount; ++i)
	{
		//Monster object 추가
		CMonster* pMonsterObj = new CMonster;
		pMonsterObj->SetPos(Vec2(((fMoveDist + fObjScale / 2.f) * 2) + (float)i * fTerm, 50.f));
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		pMonsterObj->SetMoveDistance(fMoveDist);
		pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
		AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	}

	//충돌 지정 -> 엔터에서 한번
	//player그룹과 monster그룹간의 충돌 체크
	CCollisionManager::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	//1개뿐만아니라 여러개의 충돌을 지정할 수 있음

}

void CScene_Start::Exit()
{

}
