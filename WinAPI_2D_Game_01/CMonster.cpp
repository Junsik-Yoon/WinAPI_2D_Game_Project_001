#include "pch.h"
#include "CMonster.h"

CMonster::CMonster()
{
	SetScale(fPoint(200, 200));
	m_fVelocity = 200;
	m_fDistance = 250;
	m_bIsUpDir = true;
}

CMonster::~CMonster()
{
}

void CMonster::update()
{
	fPoint vPos = GetPos();
	
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
}
