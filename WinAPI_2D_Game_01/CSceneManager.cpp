#include "pch.h"
#include "CSceneManager.h"
#include "CScene_Start.h"

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
	//���� ���� ��� ����ó��
	if (m_arrScene[(UINT)group]==m_pCurScene)
		return;
	m_pCurScene->Exit();
	m_pCurScene = m_arrScene[(UINT)group];
	m_pCurScene->Enter();
}

void CSceneManager::update()
{
	m_pCurScene->update(); //���� ���õ� �� ������Ʈ
	m_pCurScene->finalupdate();
}

void CSceneManager::render(HDC hDC)
{
	m_pCurScene->render(hDC); //���� ���õ� �� ���� 
}

void CSceneManager::init()
{


	m_arrScene[(UINT)GROUP_SCENE::START] = new CScene_Start;
	m_arrScene[(UINT)GROUP_SCENE::START]->SetName(L"Start_Scene");

	m_pCurScene = m_arrScene[(UINT)GROUP_SCENE::START];//���������
	m_pCurScene->Enter();
}
