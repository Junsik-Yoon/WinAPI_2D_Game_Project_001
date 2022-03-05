#pragma once
#include "CGameObject.h"

class CTexture;

class CTile :public CGameObject
{

private:
	CTexture* m_pTex;

public:

	virtual void update();
	virtual void render(HDC hDC);


public:
	CTile();
	~CTile();
	virtual CTile* Clone() { return new CTile(*this); }


};

