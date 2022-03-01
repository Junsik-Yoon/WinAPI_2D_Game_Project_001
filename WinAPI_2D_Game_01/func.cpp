#include "pch.h"
#include "func.h"

#include "CEventManager.h"

void CreateObject(CObject* _pObj, GROUP_TYPE _eGroup)
{
	tEvent evn = {};
	evn.eEvent = EVENT_TYPE::CREATE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;//DWORD_PTR->32비트냐 64비트냐에따라 4바이트 8바이트 달라짐
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
