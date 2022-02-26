#pragma once

class CScene;

class CSceneManager
{
	SINGLETON(CSceneManager);
private:
	CScene* m_arrScene[(UINT)GROUP_SCENE::SIZE];
	CScene* m_pCurScene;

public:

	void ChangeScene(GROUP_SCENE group);
	void update();
	void render(HDC hDC);
	void init();

	CScene* GetCurScene() { return m_pCurScene; };
};

