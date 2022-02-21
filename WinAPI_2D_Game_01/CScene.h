#pragma once

class CGameObject;//��ü�� ���� �ϴ� �ִ°͸� �˸��� ���漱�� -> ������Ÿ�����ιۿ� ����� �� ����
//���漱��: �ش� Ŭ������ ������ ������ ����� �� �ְ� ����.
//1. ��������� ������ ȣ��Ǿ� #pragma once ����θ� Ȯ�� �Ұ��� ���� �ذ�
//2. ���� ������ �����ϴ� ���¸� ���� ������ �ӵ��� ���� �� �ִ�.
class CScene
{
	vector<CGameObject*> m_arrObj[(UINT)GROUP_GAMEOBJ::SIZE];
	wstring m_strName;
public:
	CScene();
	~CScene();

	virtual void update();
	virtual void render(HDC hDC);

	void SetName(const wstring& strName) { m_strName = strName; }
	wstring GetName() { return m_strName; }

	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ type);
};

