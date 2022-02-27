#include "pch.h"
#include "CMonster.h"

#include "CTimeManager.h"
#include "CCollider.h"

CMonster::CMonster()
	:m_fSpeed(100.f),
	m_vCenterPos(Vec2(0.f, 0.f)),
	m_fMaxDistance(50.f),
	m_iDir(1)
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(40.f, 40.f));
}

CMonster::~CMonster()
{
}

void CMonster::OnCollisionEnter(CCollider* _pOther)
{
	//충돌시 할 것
	//CObject* pOtherObj = _pOther->GetObj();
	//if(pOtherObj->GetName() == L"Missile")
	//{
	// 미사일 맞으면 삭제되게 할 때 그냥 삭제시키면 벡터안에서 포인터를 빼줘야함
	//}

}

void CMonster::update()
{
	Vec2 vCurPos = GetPos();

	//잔행방향으로 시간당 m_fSpeed만큼 이동
	vCurPos.x += fDT * m_fSpeed * m_iDir;
	
	// 배회 거리 기준량을 넘어섰는지 체크
	float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDistance;//좌우로 이동해야하는 거리를 초과한경우 초과량
	if (0.f<fDist)
	{
		//방향변경
		m_iDir *= -1;
		vCurPos.x += fDist * m_iDir;
	}

	SetPos(vCurPos);
}
