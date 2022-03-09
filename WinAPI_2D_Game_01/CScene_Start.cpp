#include "pch.h"
#include "CScene_Start.h"
#include "CGameObject.h"
#include "CScene_Tool.h"


CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::update()
{
	CScene::update();
	if (KEYDOWN(VK_ESCAPE))
	{
		CEventManager::getInst()->EventChangeScene(GROUP_SCENE::TOOL);
	}
}

void CScene_Start::Enter()
{
	wstring path = CPathManager::getInst()->GetContentPath();
	//파일이름유의 -> 불러올파일이름
	path += L"Tile\\test.tile";
	LoadTile(path);

	CCameraManager::getInst()->SetLookAt(Vec2((float)WINSIZEX / 2.f, (float)WINSIZEY / 2.f));

}

void CScene_Start::Exit()
{
	DeleteAll();

	CCollisionManager::getInst()->Reset();
}
