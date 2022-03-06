#pragma once
#include "CScene.h"

class CGameObject;

class CScene_Start : public CScene
{
private:

	float fWaitDeadMotion;
	bool isDead;
	
	CGameObject* pPlayer;
public:
	virtual void update();
	
	virtual void Enter();
	virtual void Exit();

	
	void SetPlayer(CGameObject* pObj) { pPlayer = pObj; }
	CGameObject* GetPlayer() { return pPlayer; }
public:
	CScene_Start();
	virtual ~CScene_Start();
};

