#include "pch.h"
#include "CMissile.h"

CMissile::CMissile()
{
	m_fVelocity = 500;
	SetScale(fVec2(25, 25));
	
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	fVec2 vPos = GetPos();

	vPos.x += 600.f * m_fDir.x * fDT;
	vPos.y += 600.f * m_fDir.y * fDT;

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
