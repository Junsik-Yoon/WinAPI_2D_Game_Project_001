#include "pch.h"
#include "CScene_Tool.h"


CScene_Tool::CScene_Tool()
{
}

CScene_Tool::~CScene_Tool()
{
}

void CScene_Tool::update()
{
	CScene::update();
	if (KEYDOWN(VK_TAB))
	{
		CHANGESCENE(GROUP_SCENE::START);
	}
}

void CScene_Tool::Enter()
{
}

void CScene_Tool::Exit()
{
	DeleteAll();
	CCollisionManager::getInst()->Reset();
}

