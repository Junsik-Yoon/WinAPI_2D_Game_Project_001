#include "pch.h"
#include "CScene_Start.h"

#include "CObject.h"

#include "CPlayer.h"
#include "CMonster.h"

#include "CCore.h"

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

	pObj->SetPos(fPoint(640.f,384.f));
	pObj->SetScale(fPoint(100.f,100.f));

	AddObject(pObj, GROUP_TYPE::DEFAULT);
//m_arrObj[(UINT)GROUP_TYPE::DEFAULT].push_back(pObj);
	
	//���� ��ġ
	//fPoint vResolotion = CCore::GetInst()->GetResolution();
	int iMonCount = 10;
	float fMoveDist = 25.f;
	float fObjScale = 50.f;
	float fTerm = (WINSIZEX - ((fMoveDist+fObjScale/2.f) * 2)) / iMonCount - 1;
	CMonster* pMonsterObj = nullptr;
	for (int i = 0; i < iMonCount; ++i)
	{
		//Monster object �߰�
		CMonster* pMonsterObj = new CMonster;
		pMonsterObj->SetPos(fPoint(((fMoveDist + fObjScale / 2.f) * 2) + (float)i * fTerm, 50.f));
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		pMonsterObj->SetMoveDistance(fMoveDist);
		pMonsterObj->SetScale(fPoint(fObjScale, fObjScale));
		AddObject(pMonsterObj, GROUP_TYPE::DEFAULT);
	}
}

void CScene_Start::Exit()
{
}
