#pragma once
#include "CGameObject.h"
class CPlayer :public CGameObject
{
public:
	CPlayer();
	~CPlayer();

private:
	fVec2 m_fptScale;
	double m_velocity;
	int hp;
	float m_acc;
	float m_grav;
	bool isAir;
	bool isUpside;

public:
	void update();
	void render(HDC hDC);

	void CreateMissile();
};

