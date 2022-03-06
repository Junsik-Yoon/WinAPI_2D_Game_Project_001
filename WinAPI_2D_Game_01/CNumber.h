#pragma once
#include "CGameObject.h"
class CNumber : public CGameObject
{

private:
	CTexture* m_pTex;

public:

	virtual void update();
	virtual void render(HDC hDC);

public:
	CNumber();
	~CNumber();
	virtual CNumber* Clone() { return new CNumber(*this); }
};

