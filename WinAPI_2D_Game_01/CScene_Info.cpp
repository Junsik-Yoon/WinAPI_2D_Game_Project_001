#include "pch.h"
#include "CScene_Info.h"
#include "CInfo.h"
#include "CNumber.h"

CScene_Info::CScene_Info()
{
	fTimeCounter = 0.f;
}

CScene_Info::~CScene_Info()
{
}

void CScene_Info::update()
{
	CScene::update();
	fTimeCounter += fDT;
	if (fTimeCounter >= 3.f)
	{
		CEventManager::getInst()->EventChangeScene(GROUP_SCENE::START);
	}//TODO: �� �� ������ �� ȭ������ ��ȯ�Ǵµ� �� ��° ������ �������� ȭ�� ��ȯ�� �ȵ˴ϴ�..
}

void CScene_Info::Enter()
{
	CGameObject* pInfo = new CInfo();
	pInfo->SetPos(Vec2((float)WINSIZEX/2.f,(float)WINSIZEY / 2.f));
	pInfo->SetScale(Vec2(1.f, 1.f));
	AddObject(pInfo, GROUP_GAMEOBJ::DEFAULT);

	CGameObject* pNumber = new CNumber();
	pNumber->SetPos(Vec2(326.f,250.f));
	pNumber->SetScale(Vec2(1.f, 1.f));
	AddObject(pNumber, GROUP_GAMEOBJ::DEFAULT);
}

void CScene_Info::Exit()
{
	DeleteAll();

	CCollisionManager::getInst()->Reset();
}


