#pragma once
#include "CObject.h"

class CTexture;

class CPlayer : public CObject
{
public:
	virtual void update();
	virtual void render(HDC _dc);
private:
	CTexture* m_pTex;
private:
	void CreateMissile();

public:
	CPlayer();
	~CPlayer();
};

