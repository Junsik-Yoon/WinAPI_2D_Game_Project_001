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
			if(false == m_arrObj[i][j]->isDead())
			m_arrObj[i][j]->update();
		}
	}
}

void CScene::finalupdate()
{
	for (UINT i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; ++i)
	{
		for (int j = 0; j < m_arrObj[i].size(); ++j)
		{
			m_arrObj[i][j]->finalupdate();
		}
	}
}

void CScene::render(HDC hDC)
{
	//씬이 가지고 있는 모든 오브젝트들을 렌더해준다
	for (UINT i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; ++i)
	{
		vector<CGameObject*>::iterator iter = m_arrObj[i].begin();
		for (; iter != m_arrObj[i].end();)
		{
			if (false == (*iter)->isDead())
			{
				(*iter)->render(hDC);
				++iter;
			}
			else
			{
				iter = m_arrObj[i].erase(iter);;
			}
		}
	}
}

void CScene::AddObject(CGameObject* pObj, GROUP_GAMEOBJ type)
{
	m_arrObj[(UINT)type].push_back(pObj);
}

void CScene::DeleteGroup(GROUP_GAMEOBJ obj)
{
	for (int i = 0; i < m_arrObj[(UINT)obj].size(); i++)
	{
		delete m_arrObj[(UINT)obj][i];
	}
	m_arrObj[(UINT)obj].clear();
}

void CScene::DeleteAll()
{
	for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; ++i)
	{
		DeleteGroup((GROUP_GAMEOBJ)i);
	}
}

void CScene::ClearObject()
{
}
