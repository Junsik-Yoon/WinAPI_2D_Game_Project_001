#pragma once
#include "CGameObject.h"

class CTexture;

class CPlayer :public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();

private:
	fPoint m_fptScale;
	double m_velocity;
	CTexture* m_pTex;

public:
	void update();
	void render(HDC hDC);

	void CreateMissile();
};

