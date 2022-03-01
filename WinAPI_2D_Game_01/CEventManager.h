#pragma once

struct tEvent
{
	EVENT_TYPE	eEvent;
	DWORD_PTR	lParam;
	DWORD_PTR	wParam;
};

class CEventManager
{
	SINGLETON(CEventManager);
private:
	vector<tEvent> m_vecEvent;

	vector<CObject*> m_vecDead; //����(��ü�»��������ʾ����� ���������ӿ� ���ﰴü)�迭

public:
	void update();
private:
	void Execute(const tEvent& _eve);

public:
	void AddEvent(const tEvent& _eve) { m_vecEvent.push_back(_eve); }
};

