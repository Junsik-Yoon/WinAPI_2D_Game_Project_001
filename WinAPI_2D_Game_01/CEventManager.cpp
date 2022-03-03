#include "pch.h"
#include "CEventManager.h"
#include "CScene.h"
#include "CGameObject.h"

CEventManager::CEventManager()
{

}
CEventManager::~CEventManager()
{

}

void CEventManager::Execute(const tEvent& event)
{
	switch (event.eEvent)
	{
	case TYPE_EVENT::CRAETE_OBJECT:
	{
		//lParam: Object 주소
		//wParam: group type
		CGameObject* pObj = (CGameObject*)event.lParam;
		GROUP_GAMEOBJ group = (GROUP_GAMEOBJ)event.wParam;
		CSceneManager::getInst()->GetCurScene()->AddObject(pObj, group);

	}
		break;
	case TYPE_EVENT::DELETE_OBJECT:
	{
		//delete object
		//lParam: object 주소
		//죽을 예정인 오브젝트 관리
		CGameObject* pObj = (CGameObject*)event.lParam;
		pObj->SetDead();
		m_vecDead.push_back(pObj);
	}
		break;
	case TYPE_EVENT::CHANGE_SCENE:
	{
		//change scene
		//lParam:scene group type
		GROUP_SCENE scene = (GROUP_SCENE)event.lParam;
		CSceneManager::getInst()->ChangeScene(scene);
	}
		break;
	}
}

void CEventManager::update()
{
	//등록된 삭제 예정 오브젝트들을 삭제
	for(int i = 0; i < m_vecDead.size(); ++i)
	{
		delete m_vecDead[i];
	}
	m_vecDead.clear();

	//이벤트처리
	for (int i = 0; i < m_vecEvent.size(); ++i)
	{
		Execute(m_vecEvent[i]);
	}
	m_vecEvent.clear();
}

void CEventManager::EventCreateGameObject(CGameObject* pObj, GROUP_GAMEOBJ group)
{
	tEvent event;
	event.eEvent = TYPE_EVENT::CRAETE_OBJECT;
	event.lParam = (DWORD_PTR)pObj;
	event.wParam = (DWORD_PTR)group;
	AddEvent(event);
}

void CEventManager::EventDeleteGameObject(CGameObject* pObj)
{
	tEvent event;
	event.eEvent = TYPE_EVENT::DELETE_OBJECT;
	event.lParam = (DWORD_PTR)pObj;
	AddEvent(event);
}

void CEventManager::EventChangeScene(GROUP_SCENE scene)
{
	tEvent event;
	event.eEvent = TYPE_EVENT::CHANGE_SCENE;
	event.lParam = (DWORD_PTR)scene;
	AddEvent(event);
}

void CEventManager::AddEvent(const tEvent& event)
{
	m_vecEvent.push_back(event);
}
