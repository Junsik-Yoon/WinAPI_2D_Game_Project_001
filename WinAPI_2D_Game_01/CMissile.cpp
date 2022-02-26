#include "pch.h"
#include "CMissile.h"

CMissile::CMissile()
{
	m_fVelocity = 500;
	SetScale(fPoint(25, 25));
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	fPoint vPos = GetPos();

	vPos.x += (float)(m_fVelocity * m_fDir.x * DT);
	vPos.y += (float)(m_fVelocity * m_fDir.x * DT);

	SetPos(vPos);
}

void CMissile::render(HDC hDC)
{
	fPoint vPos = GetPos();
	fPoint vScale = GetScale();
	Ellipse(hDC,
		(int)vPos.x - vScale.x / 2.f,
		(int)vPos.y - vScale.y / 2.f,
		(int)vPos.x + vScale.x / 2.f,
		(int)vPos.y + vScale.y / 2.f);
}
