#pragma once
#include "CScene.h"
class CScene_Start : public CScene
{
private:

public:
	virtual void update();
	
	virtual void Enter();
	virtual void Exit();
public:
	CScene_Start();
	virtual ~CScene_Start();
};

