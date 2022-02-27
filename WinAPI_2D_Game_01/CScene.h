#pragma once

class CObject;
//전방선언을 했기때문에 클래스 자체를 쓸 수는 없다 포인터로 씀
//직접  object헤더를 참조하면 오브젝트쪽 코드가 변경되면 씬쪽도 매번 확인을 해야하므로 컴파일속도 영향을 준다


class CScene
{
private:
	//오브젝트를 그룹별로 분류 -> enum
	//자식클래스 타입의 주소는 부모포인터타입으로 다 받을수 있으므로 모든 오브젝트들은 cobject타입으로 받을 수 있다
//	vector<CObject*> vecObj; //벡터가 그룹 개수만큼 따로 존재해야한다
	
	vector<CObject*>	m_arrObj[(UINT)GROUP_TYPE::END]; //오브젝트를 저장 및 관리할 벡터를 그룹 개수만큼 선언
	wstring				m_strName;	//Scene 이름
public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	void update();
	void finalupdate(); //모든걸 마무리해주는 업데이트
	void render(HDC _dc);


	virtual void Enter() = 0;//해당 씬 진입시에 호출 //순수가상함수로 구현
	virtual void Exit() = 0; //해당 씬 나갈시에 호출

public:
	void AddObject(CObject* _pObj, GROUP_TYPE _eType) { m_arrObj[(UINT)_eType].push_back(_pObj); }
	const vector<CObject*>& GetGroupObject(GROUP_TYPE _eType) { return m_arrObj[(UINT)_eType]; }

public:
	CScene();
	virtual ~CScene();//상속목적만으로 만든 클래스이므로 버츄얼소멸자사용
};

