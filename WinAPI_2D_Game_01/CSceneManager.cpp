#include "pch.h"
#include "CSceneManager.h"

#include "CScene_Start.h"
#include "CScene_Stage.h"
#include "CScene_Ending.h"
CSceneManager::CSceneManager()
	:m_arrScene{}
	, m_pCurScene(nullptr)
{
}
CSceneManager::~CSceneManager()
{
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}

void CSceneManager::init()
{

	m_arrScene[(UINT)SCENE_TYPE::START] = new CScene_Start;
	m_arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start Scene");
	m_arrScene[(UINT)SCENE_TYPE::STAGE] = new CScene_Stage;
	m_arrScene[(UINT)SCENE_TYPE::STAGE]->SetName(L"Stage Scene");
	m_arrScene[(UINT)SCENE_TYPE::ENDING] = new CScene_Ending;
	m_arrScene[(UINT)SCENE_TYPE::ENDING]->SetName(L"Ending Scene");

	//현재 씬 지정
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START];
	m_pCurScene->Enter();
}

void CSceneManager::update()
{
	if (KEY_TAP(KEY::SPACE)) 
	{
		if (m_pCurScene != m_arrScene[(UINT)SCENE_TYPE::START]);
		else 
		{
			m_pCurScene->Exit();
			m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::STAGE];
			m_pCurScene->Enter();
		}
	}
	if (KEY_TAP(KEY::ENTER))
	{
		if (m_pCurScene != m_arrScene[(UINT)SCENE_TYPE::STAGE]);
		else
		{
			m_pCurScene->Exit();
			m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START];
			m_pCurScene->Enter();
		}
	}
	if (KEY_TAP(KEY::ESC))		//게임종료
		PostQuitMessage(0);


	m_pCurScene->update();
}

void CSceneManager::render(HDC _dc)
{
	m_pCurScene->render(_dc);
}
