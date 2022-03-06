#include "pch.h"
#include "CScene_Start.h"
#include "CGameObject.h"
#include "CMario.h"
#include "CTile.h"
#include "CMidLine.h"
#include "CBackground.h"
#include "CCollider.h"
#include "CMushroom.h"
#include "CFoot.h"



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

	CGameObject* pBG = new CBackground();
	pBG->SetPos(Vec2(3370.f, ((float)WINSIZEY / 2.f)-10.f));
	pBG->SetScale(Vec2(1.f, 1.f));
	AddObject(pBG, GROUP_GAMEOBJ::DEFAULT);

	CGameObject* pMario = new CMario();
	pMario->SetPos(Vec2(100.f,360.f) );
	AddObject(pMario, GROUP_GAMEOBJ::PLAYER);



	CGameObject* pMushroom1 = new CMushroom();
	pMushroom1->SetPos(Vec2(300.f, 380.f));
	pMushroom1->SetName(L"Mushroom");
	AddObject(pMushroom1, GROUP_GAMEOBJ::MONSTER);


	//CGameObject* pTile = nullptr;
	//for (UINT i = 0; i < 100; ++i)
	//{
	//	CGameObject* pTile = new CTile();
	//	pTile->SetPos(Vec2(pTile->GetScale().x / 2 + (float)i * 32.f, (float)WINSIZEY - 35.f));
	//	pTile->SetName(L"Tile");
	//	AddObject(pTile, GROUP_GAMEOBJ::LAND);
	//}
	CGameObject* pTile = new CTile();
	pTile->SetPos(Vec2(1000.f, (float)WINSIZEY - 50.f));
	pTile->SetScale(Vec2(2405.f, 32.f));
	pTile->SetName(L"Tile");
	pTile->CreateCollider();
	pTile->GetCollider()->SetScale(Vec2(pTile->GetScale().x, pTile->GetScale().y));
	AddObject(pTile, GROUP_GAMEOBJ::LAND);

	CGameObject* pTile2 = new CTile();
	pTile2->SetPos(Vec2(2505.f, (float)WINSIZEY - 50.f));
	pTile2->SetScale(Vec2(480.f, 32.f));
	pTile2->SetName(L"Tile");
	pTile2->CreateCollider();
	pTile2->GetCollider()->SetScale(Vec2(pTile2->GetScale().x, pTile2->GetScale().y));
	AddObject(pTile2, GROUP_GAMEOBJ::LAND);

	CGameObject* pTile3 = new CTile();
	pTile3->SetPos(Vec2(3867.f, (float)WINSIZEY - 50.f));
	pTile3->SetScale(Vec2(2045.f, 32.f));
	pTile3->SetName(L"Tile");
	pTile3->CreateCollider();
	pTile3->GetCollider()->SetScale(Vec2(pTile3->GetScale().x, pTile3->GetScale().y));
	AddObject(pTile3, GROUP_GAMEOBJ::LAND);

	CGameObject* pTile4 = new CTile();
	pTile4->SetPos(Vec2(6000.f, (float)WINSIZEY - 50.f));
	pTile4->SetScale(Vec2(2070.f, 32.f));
	pTile4->SetName(L"Tile");
	pTile4->CreateCollider();
	pTile4->GetCollider()->SetScale(Vec2(pTile4->GetScale().x, pTile4->GetScale().y));
	AddObject(pTile4, GROUP_GAMEOBJ::LAND);





	CGameObject* pMidLine = new CMidLine();
	pMidLine->SetName(L"MidLine");
	AddObject(pMidLine, GROUP_GAMEOBJ::MIDLINE);

	CGameObject* pFrontLine = new CMidLine();
	pFrontLine->SetName(L"FrontLine");
	pFrontLine->SetPos(Vec2(2.f, (float)WINSIZEY / 2.f));
	AddObject(pFrontLine, GROUP_GAMEOBJ::MIDLINE);

	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::PLAYER, GROUP_GAMEOBJ::LAND);
	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::PLAYER, GROUP_GAMEOBJ::MIDLINE);
	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::PLAYER, GROUP_GAMEOBJ::MONSTER);

	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::MONSTER, GROUP_GAMEOBJ::LAND);
	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::MONSTER, GROUP_GAMEOBJ::MIDLINE);

	CCollisionManager::getInst()->CheckGroup(GROUP_GAMEOBJ::COLLIDER, GROUP_GAMEOBJ::MONSTER);

	//CCameraManager::getInst()->SetTargetObj(pMario);
	CCameraManager::getInst()->SetLookAt(Vec2(WINSIZEX / 2.f, WINSIZEY / 2.f));

}

void CScene_Start::Exit()
{
	DeleteAll();

	CCollisionManager::getInst()->Reset();
}
