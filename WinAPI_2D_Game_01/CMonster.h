#pragma once
#include "CObject.h"

class CMonster : public CObject
{
private:
	float m_fSpeed;
	Vec2 m_vCenterPos;//���Ͱ� �¿�� �����̴� ���Ͽ����� �߾���
	float m_fMaxDistance;//�¿��̵��Ÿ�
	int m_iDir; //1,-1 �¿� �̵�����

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

