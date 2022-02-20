#pragma once

class CScene;

class CSceneManager
{
	SINGLETON(CSceneManager);
private:
	CScene* m_arrScene[(UINT)SCENE_TYPE::END]; //모든 씬을 가지고 씬 전환
	CScene* m_pCurScene; //현재 씬
	

public:
	void init();
	void update();
	void render(HDC _dc);
};

