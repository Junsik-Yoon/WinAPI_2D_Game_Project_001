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
	//���������ӿ��� ����ص� Dead Object���� �����Ѵ�
	//=============================================
	for (size_t i = 0; i < m_vecDead.size(); ++i)
	{
		delete m_vecDead[i];
	}
	m_vecDead.clear();
	


	//==========
	//Event ó��
	//==========
	for (size_t i = 0; i < m_vecEvent.size(); ++i)
	{
		Execute(m_vecEvent[i]);
	}
	m_vecEvent.clear();
}

void CEventManager::Execute(const tEvent& _eve)
{
	//���� �̺�Ʈ�� �����Ŀ����� ó��
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
		//lParam: Object Adress //������ �ּ�
		//Object�� Dead���·� �����ϰ�
		//�������� ������Ʈ���� ��Ƶд�.

		CObject* pDeadObj = (CObject*)_eve.lParam;
		pDeadObj->SetDead();
		m_vecDead.push_back(pDeadObj);
	}
		break;

	case EVENT_TYPE::SCENE_CHANGE:

		break;


	}
}
