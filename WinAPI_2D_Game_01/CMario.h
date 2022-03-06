#pragma once
#include "CGameObject.h"

class CTexture;
class CFoot;

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
	static float sCountTime;
	static float sCountTime2;
	static float sCountTime3;//죽는모션용
	
public:
	static int slife;
	static int Getlife() { return slife; }

	CFoot* m_foot;//TODO: 발 객체를 따로 만들어서 밑쪽으로 몬스터를 밟으면 발과 몬스터의충돌이면 몬스터가 죽고 마리오와 몬스터의 충돌이면 마리오가 죽게 하고 싶었는데 발객체가 마리오를 따라다니게 하고싶었는데 잘 안되네요..

	CTexture* m_pTex;
	float m_fVelocityUD;
	float m_fVelocityLR;
	STATUS m_type;

	bool isKillJump;
	bool isLittleJump; //죽이고난뒤 잔점프

	float m_fLittleVel;

	bool isBoost;
	float jumpBoost;

	bool is_dead;//마리오생사체크토글

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

	void SetLittleJump(bool isKilled) { isLittleJump = isKilled; isUpside = true; }

	void CreateFoot();
	CFoot* GetFoot() { return m_foot; }

public:
	virtual void update();
	virtual void render(HDC hDC);

public:
	CMario();
	~CMario();
	virtual CMario* Clone(){ return new CMario(*this); }
};

