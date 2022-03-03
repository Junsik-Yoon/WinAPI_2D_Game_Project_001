#pragma once

class CGameObject;

struct tEvent
{
	TYPE_EVENT eEvent;	//이벤트타입
	DWORD_PTR lParam;	//추가적인 정보1 (ptr)
	DWORD_PTR wParam;	//추가적인 정보2 (ptr)
};

class CEventManager
{
	SINGLETON(CEventManager);
	

private:
	vector<tEvent> m_vecEvent;
	vector<CGameObject*> m_vecDead;

	void Execute(const tEvent& event);
public:
	void update();
	
	void EventCreateGameObject(CGameObject* pObj, GROUP_GAMEOBJ group);
	void EventDeleteGameObject(CGameObject* pObj);
	void EventChangeScene(GROUP_SCENE scene);//씬 전환 이벤트

	void AddEvent(const tEvent& event);//이벤트 매니저의 대기열에 이벤트 추가
};

