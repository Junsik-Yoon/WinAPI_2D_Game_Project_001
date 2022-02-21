#include "pch.h"
#include "CMonster.h"

#include "CTimeManager.h"

CMonster::CMonster()
	:m_fSpeed(100.f),
	m_vCenterPos(fPoint(0.f, 0.f)),
	m_fMaxDistance(50.f),
	m_iDir(1)
{
}

CMonster::~CMonster()
{
}

void CMonster::update()
{
	fPoint vCurPos = GetPos();

	//����������� �ð��� m_fSpeed��ŭ �̵�
	vCurPos.x += fDT * m_fSpeed * m_iDir;
	
	// ��ȸ �Ÿ� ���ط��� �Ѿ���� üũ
	float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDistance;//�¿�� �̵��ؾ��ϴ� �Ÿ��� �ʰ��Ѱ�� �ʰ���
	if (0.f<fDist)
	{
		//���⺯��
		m_iDir *= -1;
		vCurPos.x += fDist * m_iDir;
	}

	SetPos(vCurPos);
}
