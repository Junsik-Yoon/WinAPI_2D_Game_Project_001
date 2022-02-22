#include "pch.h"
#include "CScene_Stage1.h"
#include "CGameObject.h"

CScene_Stage1::CScene_Stage1()
{
}

CScene_Stage1::~CScene_Stage1()
{
}

void CScene_Stage1::Enter()
{
	CGameObject* pObj = new CGameObject;
	pObj->SetPos(fPoint(200, 200));
	pObj->SetScale(fPoint(100, 100));
	AddObject(pObj, GROUP_GAMEOBJ::DEFAULT);
}

void CScene_Stage1::Exit()
{
	ClearObject();
}
