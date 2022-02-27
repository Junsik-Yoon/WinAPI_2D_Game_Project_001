#include "pch.h"
#include "CMissile.h"

#include "CTimeManager.h"

CMissile::CMissile() //0이면 우측으로
	:m_fTheta(3.f * PI / 2.f)   //윈도우좌표는 위아래가 뒤집어져있기때문에 위아래를 반대로 봐야함
	, m_vDir(1.f,1.f)
{
	m_vDir.Normalize();
	CreateCollider();
}

CMissile::~CMissile()
{

}

void CMissile::update()
{
	Vec2 vPos = GetPos();
	//vPos.x += 600.f * cosf(m_fTheta) * fDT;
	//vPos.y -= 600.f * sinf(m_fTheta) * fDT;
	vPos.x += 600.f * m_vDir.x * fDT;
	vPos.y += 600.f * m_vDir.y * fDT;
	SetPos(vPos);
}

void CMissile::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	Ellipse(_dc,
		(int)vPos.x - vScale.x / 2.f,
		(int)vPos.y - vScale.y / 2.f,
		(int)vPos.x + vScale.x / 2.f,
		(int)vPos.y + vScale.y / 2.f);
}
