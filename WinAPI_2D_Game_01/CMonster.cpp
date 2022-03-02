#include "pch.h"
#include "CMonster.h"
#include "CCollider.h"

CMonster::CMonster()
{
	SetScale(fVec2(60, 60));
	m_fVelocity = 200;
	m_fDistance = 250;
	m_bIsUpDir = true;

	CreateCollider();
	GetCollider()->SetScale(fVec2(90.f, 90.f));
}

CMonster::~CMonster()
{
}

void CMonster::update()
{
	fVec2 vPos = GetPos();
	
	if (m_bIsUpDir)
	{
		vPos.y -= m_fVelocity * DT;
		if (vPos.y < m_fPtCenterPos.y-m_fDistance)
		{
			m_bIsUpDir = false;
		}
	}
	else
	{
		vPos.y += m_fVelocity * DT;
		if (vPos.y > m_fPtCenterPos.y+ m_fDistance)
		{
			m_bIsUpDir = true;
		}
	}

	SetPos(vPos);
}

void CMonster::render(HDC hDC)
{
	Rectangle(hDC, GetPos().x - GetScale().x,
		GetPos().y - GetScale().y,
		GetPos().x + GetScale().x,
		GetPos().y + GetScale().y);
	component_render(hDC);
}
