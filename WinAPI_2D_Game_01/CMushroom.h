#pragma once
#include "CGameObject.h"

class CTexture;

class CMushroom :public CGameObject
{
public:
	static float sDeleteCount;

private:

	float m_fVelocity;
	float m_fDistance;
	bool m_bIsUPDir;
	
	bool isDelete;

	CTexture* m_pTex;
	

public:
	virtual void update();
	virtual void render(HDC hDC);

	virtual void OnCollisionEnter(CCollider* pOther);
	virtual void OnCollision(CCollider* pOther);
	virtual void OnCollisionExit(CCollider* pOther);

	void DeleteEffect();

public:
	CMushroom();
	virtual ~CMushroom();
	virtual CMushroom* Clone() { return new CMushroom(*this); }
};

