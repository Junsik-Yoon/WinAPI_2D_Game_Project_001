#pragma once
#include "CGameObject.h"
class CInfo :public CGameObject
{

private:
	CTexture* m_pTex;

public:

	virtual void update();
	virtual void render(HDC hDC);

public:
	CInfo();
	~CInfo();
	virtual CInfo* Clone() { return new CInfo(*this); }
};


