#include "pch.h"
#include "CScene_Start.h"
#include "CGameObject.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{
	CGameObject* pObj = new CGameObject;
	pObj->SetPos(fPoint(200, 200));
	pObj->SetScale(fPoint(100, 100));
	AddObject(pObj, GROUP_GAMEOBJ::DEFAULT);
}

void CScene_Start::Exit()
{
	ClearObject();
}
