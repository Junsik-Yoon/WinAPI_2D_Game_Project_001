#pragma once
#include "CGameObject.h"
class CPlayer :public CGameObject
{
public:
	CPlayer();
	~CPlayer();

private:
	fPoint m_fptScale;
	double m_velocity;

public:
	void update();
	void render(HDC hDC);

	void CreateMissile();
};

