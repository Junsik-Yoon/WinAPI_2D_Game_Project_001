#include "pch.h"
#include "CMissile.h"

CMissile::CMissile()
{
	m_fVelocity = 600.f;
	SetScale(fVec2(25, 25));
	
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	fVec2 vPos = GetPos();

	m_grav = 1000.f;
	if (m_fDir.x > m_fDir.y)
	{
		vPos.x += m_fVelocity * m_fDir.x * fDT;
		vPos.y += m_fVelocity * m_fDir.y * fDT;
	}
	else
	{
		m_fVelocity -= m_grav* fDT;
		vPos.x += 800.f * m_fDir.x * fDT;
		vPos.y += m_fVelocity * m_fDir.y * fDT;
	}
	SetPos(vPos);
}

void CMissile::render(HDC hDC)
{
	fVec2 vPos = GetPos();
	fVec2 vScale = GetScale();
	Ellipse(hDC,
		(int)vPos.x - vScale.x / 2.f,
		(int)vPos.y - vScale.y / 2.f,
		(int)vPos.x + vScale.x / 2.f,
		(int)vPos.y + vScale.y / 2.f);
}