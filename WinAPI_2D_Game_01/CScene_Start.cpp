#include "pch.h"
#include "CScene_Start.h"
#include "CGameObject.h"
#include "CMario.h"
#include "CTile.h"
#include "CMidLine.h"



CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::update()
{
	CScene::update();


	if (KEYDOWN(VK_LBUTTON))
	{
		Vec2 fptLookAt = CCameraManager::getInst()->GetRealPos(MousePos());
		CCameraManager::getInst()->SetLookAt(fptLookAt);
	}
}

void CScene_Start::Enter()
{
	CGameObject* pMario = new CMario();
	pMario->SetPos(Vec2(100,360) );
	AddObject(pMario, GROUP_GAMEOBJ::PLAYER);

	CGameObject* pTile = nullptr;
	for (UINT i = 0; i < 100; ++i)
	{
		CGameObject* pTile = new CTile();
		pTile->SetPos(Vec2(pTile->GetScale().x / 2 + (float)i * 32.f, (float)WINSIZEY - 35.f));
		pTile->SetName(L"Tile");
		AddObject(pTile, GROUP_GAMEOBJ::LAND);
	}

	CGameObject* pMidLine = new CMidLine();
	pMidLine->SetName(L"MidLine");
	AddObject(pMidLine, GROUP_GAMEOBJ::MIDLINE);

	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::PLAYER, GROUP_GAMEOBJ::LAND);
	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::PLAYER, GROUP_GAMEOBJ::MIDLINE);

	//CCameraManager::getInst()->SetTargetObj(pMario);
	CCameraManager::getInst()->SetLookAt(Vec2(WINSIZEX / 2.f, WINSIZEY / 2.f));

}

void CScene_Start::Exit()
{
	DeleteAll();

	CCollisionManager::getInst()->Reset();
}
