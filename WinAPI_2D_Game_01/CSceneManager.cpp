#include "pch.h"
#include "CSceneManager.h"
#include "CScene_Start.h"
#include "CScene_Stage1.h"

CSceneManager::CSceneManager()
{
	for (UINT i = 0; i < (UINT)GROUP_SCENE::SIZE; ++i)
	{
		m_arrScene[i] = nullptr;
	}
	m_pCurScene = nullptr;
}
CSceneManager::~CSceneManager()
{
	for (UINT i = 0; i < (UINT)GROUP_SCENE::SIZE; ++i)
	{
		if (nullptr != m_arrScene[i])
			delete m_arrScene[i];
	}
//	if (nullptr != m_pCurScene)
	//	delete m_pCurScene;
}

void CSceneManager::ChangeScene(GROUP_SCENE group)
{
	//같은 씬일 경우
	if (m_arrScene[(UINT)group]==m_pCurScene)
		return;
	m_pCurScene->Exit();
	m_pCurScene = m_arrScene[(UINT)GROUP_SCENE::START];
	m_pCurScene->Enter();
}

void CSceneManager::update()
{
	if (KEYDOWN(VK_SPACE))
	{
		ChangeScene(GROUP_SCENE::STAGE1);
	}
	else if (KEYDOWN(VK_ESCAPE))
	{
		ChangeScene(GROUP_SCENE::START);
	}

	m_pCurScene->update(); //현재 선택된 씬만 업데이트
}

void CSceneManager::render(HDC hDC)
{
	m_pCurScene->render(hDC); //현재 선택된 씬만 렌더 
}

void CSceneManager::init()
{
	m_arrScene[(UINT)GROUP_SCENE::START] = new CScene_Start;
	m_arrScene[(UINT)GROUP_SCENE::START]->SetName(L"Start_Scene");

	m_arrScene[(UINT)GROUP_SCENE::STAGE1] = new CScene_Stage1;
	m_arrScene[(UINT)GROUP_SCENE::STAGE1]->SetName(L"Stage01_Scene");

	m_pCurScene = m_arrScene[(UINT)GROUP_SCENE::START];
	m_pCurScene->Enter();
}
