#pragma once
#include "CGameObject.h"

class CTexture;

class CMushroom :public CGameObject
{
private:
	float m_fVelocity;
	float m_fDistance;
	bool m_bIsUPDir;
	
	CTexture* m_pTex;
	

public:
	virtual void update();
	virtual void render(HDC hDC);

	virtual void OnCollisionEnter(CCollider* pOther);

public:
	CMushroom();
	~CMushroom();
	virtual CMushroom* Clone() { return new CMushroom(*this); }
};

