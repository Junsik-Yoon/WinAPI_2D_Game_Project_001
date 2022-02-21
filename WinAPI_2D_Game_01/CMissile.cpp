#include "pch.h"
#include "CMissile.h"

#include "CTimeManager.h"

CMissile::CMissile()
	:m_fDir(1.f)
{
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	fPoint vPos = GetPos();
	vPos.y += 600.f * fDT * m_fDir;
	SetPos(vPos);
}

void CMissile::render(HDC _dc)
{
	fPoint vPos = GetPos();
	fPoint vScale = GetScale();
	Ellipse(_dc,
		(int)vPos.x - vScale.x / 2.f,
		(int)vPos.y - vScale.y / 2.f,
		(int)vPos.x + vScale.x / 2.f,
		(int)vPos.y + vScale.y / 2.f);
}
