#include "pch.h"
#include "CSceneManager.h"
#include "CScene_Start.h"
#include "CScene_Info.h"

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
}

void CSceneManager::ChangeScene(GROUP_SCENE group)
{
	//같은 씬일 경우 예외처리
	if (m_arrScene[(UINT)group]==m_pCurScene)
		return;
	m_pCurScene->Exit();
	m_pCurScene = m_arrScene[(UINT)group];
	m_pCurScene->Enter();
}

void CSceneManager::update()
{
	m_pCurScene->update(); //현재 선택된 씬 업데이트
	m_pCurScene->finalupdate();
}

void CSceneManager::render(HDC hDC)
{
	m_pCurScene->render(hDC); //현재 선택된 씬 렌더 
}

void CSceneManager::init()
{


	m_arrScene[(UINT)GROUP_SCENE::START] = new CScene_Start;
	m_arrScene[(UINT)GROUP_SCENE::START]->SetName(L"Start_Scene");

	m_arrScene[(UINT)GROUP_SCENE::DEFAULT] = new CScene_Info;
	m_arrScene[(UINT)GROUP_SCENE::DEFAULT]->SetName(L"Info_Scene");

	m_pCurScene = m_arrScene[(UINT)GROUP_SCENE::START];
	m_pCurScene->Enter();
}
