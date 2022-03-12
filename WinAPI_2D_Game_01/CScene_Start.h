#pragma once
#include "CScene.h"
class CScene_Start : public CScene
{
private:
	float m_velocity = 300;
public:
	CScene_Start();
	~CScene_Start();
	virtual void update();
	virtual void Enter();
	virtual void Exit();
};

