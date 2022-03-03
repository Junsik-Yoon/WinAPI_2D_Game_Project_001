#include "pch.h"
#include "CMissile.h"
#include "CCollider.h"

CMissile::CMissile()
{
	SetName(L"Missile");
	m_fVelocity = 500;
	SetScale(fVec2(25, 25));

	CreateCollider();
	GetCollider()->SetScale(fVec2(20.f, 20.f));
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	fVec2 vPos = GetPos();

	vPos.x += (float)(m_fVelocity * m_fDir.x * DT);
	vPos.y += (float)(m_fVelocity * m_fDir.x * DT);

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
	component_render(hDC);
}
