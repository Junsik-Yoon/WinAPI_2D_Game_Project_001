#pragma once
#include "CObject.h"

class CMonster : public CObject
{
private:
	float m_fSpeed;
	Vec2 m_vCenterPos;//몬스터가 좌우로 움직이는 패턴에서의 중앙점
	float m_fMaxDistance;//좌우이동거리
	int m_iDir; //1,-1 좌우 이동방향

	int m_iHP;

public:
	float GetSpeed() { return m_fSpeed; }
	void SetSpeed(float _fSpeed) { m_fSpeed=_fSpeed; }
	void SetMoveDistance(float _MaxDistance) { m_fMaxDistance = _MaxDistance; }
	void SetCenterPos(Vec2 _vPos) { m_vCenterPos=_vPos; }

	

public:
	virtual void OnCollisionEnter(CCollider* _pOther);

public:
	virtual void update();
public:
	CMonster();
	~CMonster();
};

