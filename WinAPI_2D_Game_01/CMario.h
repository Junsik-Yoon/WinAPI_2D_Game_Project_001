#pragma once
#include "CGameObject.h"

class CTexture;

enum class STATUS
{
	SMALL,
	LARGE,
	FLOWER,
	SIZE,
};

class CMario: public CGameObject
{
private:
	CTexture* m_pTex;
	float m_fVelocityUD;
	float m_fVelocityLR;
	STATUS m_type;

	bool isFacedRight;

	float m_fAcc; //가속
	float m_fGrav;//중력
	bool isAir;
	bool isUpside;
	bool canJump;

public:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	//virtual void OnCollisionNone(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);
	
public:
	void SetAcc(float acc) { m_fAcc = acc; }

public:
	virtual void update();
	virtual void render(HDC hDC);

public:
	CMario();
	~CMario();
	virtual CMario* Clone(){ return new CMario(*this); }
};

