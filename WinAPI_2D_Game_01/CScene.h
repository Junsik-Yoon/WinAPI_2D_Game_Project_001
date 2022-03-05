#pragma once

class CGameObject;

class CScene
{
	vector<CGameObject*> m_arrObj[(UINT)GROUP_GAMEOBJ::SIZE];
	wstring m_strName;
public:
	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC hDC);

	virtual void Enter()=0;
	virtual void Exit()=0;

	void SetName(const wstring& strName) { m_strName = strName; }
	wstring GetName() { return m_strName; }

	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ type);
	const vector<CGameObject*>& GetGroupObject(GROUP_GAMEOBJ group){ return m_arrObj[(UINT)group]; }
	void DeleteGroup(GROUP_GAMEOBJ group);
	void DeleteAll();

public:
	CScene();
	virtual ~CScene();
};

