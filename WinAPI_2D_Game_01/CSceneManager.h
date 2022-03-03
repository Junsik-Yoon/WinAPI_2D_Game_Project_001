#pragma once

class CScene;//���漱��

class CSceneManager
{
	SINGLETON(CSceneManager);
	friend class CEventManager;
private:
	CScene* m_arrScene[(UINT)GROUP_SCENE::SIZE];
	CScene* m_pCurScene;

public:

	void ChangeScene(GROUP_SCENE group); //����ȯ
	void update();
	void render(HDC hDC);
	void init();

	CScene* GetCurScene() { return m_pCurScene; };
};

