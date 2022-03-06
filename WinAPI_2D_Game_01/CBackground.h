#pragma once
#include "CGameObject.h"

class CBackground : public CGameObject
{

private:
	CTexture* m_pTex;

public:

	virtual void update();
	virtual void render(HDC hDC);

public:
	CBackground();
	~CBackground();
	virtual CBackground* Clone() { return new CBackground(*this); }
};

