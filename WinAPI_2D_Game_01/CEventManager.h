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

	vector<CObject*> m_vecDead; //데드(객체는삭제되지않았지만 다음프레임에 지울객체)배열

public:
	void update();
private:
	void Execute(const tEvent& _eve);

public:
	void AddEvent(const tEvent& _eve) { m_vecEvent.push_back(_eve); }
};

