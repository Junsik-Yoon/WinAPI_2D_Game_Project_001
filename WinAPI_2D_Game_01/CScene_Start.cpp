#include "pch.h"
#include "CScene_Start.h"

#include "CObject.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
	
}


void CScene_Start::Enter()
{
	//objectÃß°¡
	CObject* pObj = new CObject;

	pObj->SetPos(fPoint(640.f,384.f));
	pObj->SetScale(fPoint(100.f,100.f));

	AddObject(pObj, GROUP_TYPE::DEFAULT);

	//m_arrObj[(UINT)GROUP_TYPE::DEFAULT].push_back(pObj);

}

void CScene_Start::Exit()
{
}
