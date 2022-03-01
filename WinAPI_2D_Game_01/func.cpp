#include "pch.h"
#include "func.h"

#include "CEventManager.h"

void CreateObject(CObject* _pObj, GROUP_TYPE _eGroup)
{
	tEvent evn = {};
	evn.eEvent = EVENT_TYPE::CREATE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;//DWORD_PTR->32��Ʈ�� 64��Ʈ�Ŀ����� 4����Ʈ 8����Ʈ �޶���
	evn.wParam = (DWORD_PTR)_eGroup;

	CEventManager::GetInst()->AddEvent(evn);
}

void DeleteObject(CObject* _pObj)
{
	tEvent evn = {};
	evn.eEvent = EVENT_TYPE::DELETE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;
	

	CEventManager::GetInst()->AddEvent(evn);
}
