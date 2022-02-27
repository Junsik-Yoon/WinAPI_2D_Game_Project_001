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
	//Player object�߰�
	CObject* pObj = new CPlayer;//������ �����Ȱ�ü�� �÷��̾����� �÷��̾��� �ּҸ� ������ �θ�������Ÿ��

	pObj->SetPos(Vec2(640.f, 384.f));
	pObj->SetScale(Vec2(100.f, 100.f));

	AddObject(pObj, GROUP_TYPE::PLAYER);


	//���� ��ġ
	int iMonCount = 1;
	float fMoveDist = 25.f;
	float fObjScale = 50.f;
	float fTerm = (WINSIZEX - ((fMoveDist + fObjScale / 2.f) * 2)) / iMonCount - 1;
	CMonster* pMonsterObj = nullptr;
	for (int i = 0; i < iMonCount; ++i)
	{
		//Monster object �߰�
		CMonster* pMonsterObj = new CMonster;
		pMonsterObj->SetPos(Vec2(((fMoveDist + fObjScale / 2.f) * 2) + (float)i * fTerm, 50.f));
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		pMonsterObj->SetMoveDistance(fMoveDist);
		pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
		AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	}

	//�浹 ���� -> ���Ϳ��� �ѹ�
	//player�׷�� monster�׷찣�� �浹 üũ
	CCollisionManager::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	//1���Ӹ��ƴ϶� �������� �浹�� ������ �� ����

}

void CScene_Start::Exit()
{

}
