#include "pch.h"
#include "CScene.h"
#include "CGameObject.h"

CScene::CScene()
{
	m_strName = L"";
}

CScene::~CScene()
{
	for (UINT i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; ++i)
	{
		for (int j = 0; j < m_arrObj[i].size(); ++j)
		{
			delete m_arrObj[i][j];
		}
	}
}

void CScene::update()
{
	//씬이 가지고 있는 모든 오브젝트들을 업데이트해준다
	for (UINT i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; ++i)
	{
		for (int j = 0; j < m_arrObj[i].size(); ++j)
		{
			m_arrObj[i][j]->update();
		}
	}
}

void CScene::render(HDC hDC)
{
	//씬이 가지고 있는 모든 오브젝트들을 렌더해준다
	for (UINT i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; ++i)
	{
		for (int j = 0; j < m_arrObj[i].size(); ++j)
		{
			m_arrObj[i][j]->render(hDC);
		}
	}
}

void CScene::AddObject(CGameObject* pObj, GROUP_GAMEOBJ type)
{
	m_arrObj[(UINT)type].push_back(pObj);
}

void CScene::ClearObject()
{
}
