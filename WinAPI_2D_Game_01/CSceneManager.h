#pragma once

class CScene;

class CSceneManager
{
	SINGLETON(CSceneManager);
private:
	CScene* m_arrScene[(UINT)SCENE_TYPE::END]; //��� ���� ������ �� ��ȯ
	CScene* m_pCurScene; //���� ��
	

public:
	void init();
	void update();
	void render(HDC _dc);
};

