#pragma once

class CObject;

class CScene
{
private:

	vector<CObject*>	m_arrObj[(UINT)GROUP_TYPE::END]; 
	wstring				m_strName;	
public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	void update();
	void render(HDC _dc);


	virtual void Enter() = 0;
	virtual void Exit() = 0; 

public:
	void AddObject(CObject* _pObj, GROUP_TYPE _eType) { m_arrObj[(UINT)_eType].push_back(_pObj); }
	void Clear();
public:
	CScene();
	virtual ~CScene();//상속목적만으로 만든 클래스이므로 버츄얼소멸자사용
};
