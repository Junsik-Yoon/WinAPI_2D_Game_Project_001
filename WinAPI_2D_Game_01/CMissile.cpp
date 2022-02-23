#include "pch.h"
#include "CMissile.h"

#include "CTimeManager.h"

CMissile::CMissile() //0�̸� ��������
	:m_fTheta(3.f * PI / 2.f)   //��������ǥ�� ���Ʒ��� ���������ֱ⶧���� ���Ʒ��� �ݴ�� ������
	, m_vDir(1.f,1.f)
{
	m_vDir.Normalize();
}

CMissile::~CMissile()
{

}

void CMissile::update()
{
	fPoint vPos = GetPos();
	//vPos.x += 600.f * cosf(m_fTheta) * fDT;
	//vPos.y -= 600.f * sinf(m_fTheta) * fDT;
	vPos.x += 600.f * m_vDir.x * fDT;
	vPos.y += 600.f * m_vDir.y * fDT;
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
