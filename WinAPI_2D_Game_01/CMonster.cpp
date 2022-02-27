#include "pch.h"
#include "CMonster.h"

#include "CTimeManager.h"
#include "CCollider.h"

CMonster::CMonster()
	:m_fSpeed(100.f),
	m_vCenterPos(Vec2(0.f, 0.f)),
	m_fMaxDistance(50.f),
	m_iDir(1)
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(40.f, 40.f));
}

CMonster::~CMonster()
{
}

void CMonster::OnCollisionEnter(CCollider* _pOther)
{
	//�浹�� �� ��
	//CObject* pOtherObj = _pOther->GetObj();
	//if(pOtherObj->GetName() == L"Missile")
	//{
	// �̻��� ������ �����ǰ� �� �� �׳� ������Ű�� ���;ȿ��� �����͸� �������
	//}

}

void CMonster::update()
{
	Vec2 vCurPos = GetPos();

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
