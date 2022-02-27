#pragma once

class CObject;
//���漱���� �߱⶧���� Ŭ���� ��ü�� �� ���� ���� �����ͷ� ��
//����  object����� �����ϸ� ������Ʈ�� �ڵ尡 ����Ǹ� ���ʵ� �Ź� Ȯ���� �ؾ��ϹǷ� �����ϼӵ� ������ �ش�


class CScene
{
private:
	//������Ʈ�� �׷캰�� �з� -> enum
	//�ڽ�Ŭ���� Ÿ���� �ּҴ� �θ�������Ÿ������ �� ������ �����Ƿ� ��� ������Ʈ���� cobjectŸ������ ���� �� �ִ�
//	vector<CObject*> vecObj; //���Ͱ� �׷� ������ŭ ���� �����ؾ��Ѵ�
	
	vector<CObject*>	m_arrObj[(UINT)GROUP_TYPE::END]; //������Ʈ�� ���� �� ������ ���͸� �׷� ������ŭ ����
	wstring				m_strName;	//Scene �̸�
public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	void update();
	void finalupdate(); //���� ���������ִ� ������Ʈ
	void render(HDC _dc);


	virtual void Enter() = 0;//�ش� �� ���Խÿ� ȣ�� //���������Լ��� ����
	virtual void Exit() = 0; //�ش� �� �����ÿ� ȣ��

public:
	void AddObject(CObject* _pObj, GROUP_TYPE _eType) { m_arrObj[(UINT)_eType].push_back(_pObj); }
	const vector<CObject*>& GetGroupObject(GROUP_TYPE _eType) { return m_arrObj[(UINT)_eType]; }

public:
	CScene();
	virtual ~CScene();//��Ӹ��������� ���� Ŭ�����̹Ƿ� �����Ҹ��ڻ��
};

