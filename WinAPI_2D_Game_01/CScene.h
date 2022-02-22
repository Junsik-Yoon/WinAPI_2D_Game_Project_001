#pragma once

class CGameObject;//실체는 없고 일단 있는것만 알리는 전방선언 -> 포인터타입으로밖에 사용할 수 없음
//전방선언: 해당 클래스의 포인터 변수를 사용할 수 있게 해줌.
//1. 헤더파일이 여러번 호출되어 #pragma once 선언부를 확인 불가한 문제 해결
//2. 서로 여러번 참조하는 형태를 피해 컴파일 속도를 줄일 수 있다.
class CScene
{
	vector<CGameObject*> m_arrObj[(UINT)GROUP_GAMEOBJ::SIZE];
	wstring m_strName;
public:
	CScene();
	virtual ~CScene();

	virtual void update();
	virtual void render(HDC hDC);

	virtual void Enter()=0;//씬이라는 자기자신을 만들 일이 없기때문에 순수가상함수
	virtual void Exit()=0;

	void SetName(const wstring& strName) { m_strName = strName; }
	wstring GetName() { return m_strName; }

	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ type);
protected:
	void ClearObject();
};

