#include "pch.h"
#include "CEventManager.h"
#include "CObject.h"
#include "CSceneManager.h"
#include "CScene.h"

CEventManager::CEventManager()
{

}
CEventManager::~CEventManager()
{

}

void CEventManager::update()
{

	//=============================================
	//이전프레임에서 등록해둔 Dead Object들을 삭제한다
	//=============================================
	for (size_t i = 0; i < m_vecDead.size(); ++i)
	{
		delete m_vecDead[i];
	}
	m_vecDead.clear();
	


	//==========
	//Event 처리
	//==========
	for (size_t i = 0; i < m_vecEvent.size(); ++i)
	{
		Execute(m_vecEvent[i]);
	}
	m_vecEvent.clear();
}

void CEventManager::Execute(const tEvent& _eve)
{
	//무슨 이벤트가 들어오냐에따라 처리
	switch (_eve.eEvent)
	{
	case EVENT_TYPE::CREATE_OBJECT:
	{	//lParam: Object Adress
		//wParam: Group Type

		CObject* pNewObj = (CObject*)_eve.lParam;
		GROUP_TYPE eType = (GROUP_TYPE)_eve.wParam;

		CSceneManager::GetInst()->GetCurScene()->AddObject(pNewObj, eType);
		
	}
		break;
	
	case EVENT_TYPE::DELETE_OBJECT:
	{
		//lParam: Object Adress //삭제할 주소
		//Object를 Dead상태로 변경하고
		//삭제예정 오브젝트들을 모아둔다.

		CObject* pDeadObj = (CObject*)_eve.lParam;
		pDeadObj->SetDead();
		m_vecDead.push_back(pDeadObj);
	}
		break;

	case EVENT_TYPE::SCENE_CHANGE:

		break;


	}
}
