#pragma once
#include "CScene.h"
class CScene_Stage: public CScene
{
public:
	virtual void Enter();
	virtual void Exit();
public:
	CScene_Stage();
	~CScene_Stage();
};

