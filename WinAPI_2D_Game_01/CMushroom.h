#pragma once
#include "CGameObject.h"
class CMushroom :public CGameObject
{
private:
	float m_fVelocity;
	float m_fDistance;
	bool m_bIsUPDir;


public:
	virtual void update();

	void OnCollisionEnter(CCollider* pOther);

public:
	CMushroom();
	~CMushroom();
	virtual CMushroom* Clone();
};

