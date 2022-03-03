#pragma once

class CGameObject;

struct tEvent
{
	TYPE_EVENT eEvent;	//�̺�ƮŸ��
	DWORD_PTR lParam;	//�߰����� ����1 (ptr)
	DWORD_PTR wParam;	//�߰����� ����2 (ptr)
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
	void EventChangeScene(GROUP_SCENE scene);//�� ��ȯ �̺�Ʈ

	void AddEvent(const tEvent& event);//�̺�Ʈ �Ŵ����� ��⿭�� �̺�Ʈ �߰�
};

