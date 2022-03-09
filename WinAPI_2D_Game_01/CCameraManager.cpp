#include "pch.h"
#include "CCameraManager.h"
#include "CGameObject.h"

CCameraManager::CCameraManager()
{
	m_fptLookAt = Vec2(WINSIZEX / 2.f, WINSIZEY / 2.f); // ���� �ִ� ��ġ
	m_fptCurLookAt = m_fptLookAt;						// ī�޶� ���� ���� ��ġ
	m_fptPrevLookAt = m_fptLookAt;						// ī�޶� ������ ���� ��ġ
	m_pTargetObj = nullptr;								// Ʈ��ŷ �� ������Ʈ
	
	m_fptDiff = {};										// �ػ� �߽ɰ� ī�޶� LookAt ������ ����
	m_fTime = 2;										// Ÿ���� ���󰡴� �ѽð�
	m_fAccTime = m_fTime;								// Ÿ���� ���� �ҿ�ð�
	m_fSpeed = 0;										// Ÿ���� ���󰡴� �ӵ�
	m_fPreSpeed = m_fSpeed;								// Ÿ���� ���󰡴� �ӵ�
	m_fAccel = 0;										// Ÿ���� ���󰡴� ��ӵ�
	m_fAccDir = 1.f;									// ��ӵ��� ����
}

CCameraManager::~CCameraManager()
{

}

void CCameraManager::update()
{
	if (m_pTargetObj)
	{
		if (m_pTargetObj->isDead())
		{
			m_pTargetObj = nullptr;
		}
		else
		{
			SetLookAt(m_pTargetObj->GetPos());
		}
	}

	// ȭ�� �߾Ӱ� ī�޶� LookAt ��ǥ ������ ���� ���
	CalDiff();
}


void CCameraManager::SetLookAt(Vec2 lookAt)
{
	m_fptLookAt = lookAt;
	float fMoveDist = (m_fptLookAt - m_fptPrevLookAt).Length();
	m_fAccel = fMoveDist / m_fTime;		// ��ӵ� ���
	m_fAccel *= m_fAccDir;

	if (m_fAccDir < 0) // �ʱ� �ӵ� ����
	{
		m_fSpeed = fMoveDist;
	}
	else
	{
		m_fSpeed = 0.f;
	}
	m_fAccTime = 0.f;
}

void CCameraManager::Scroll(Vec2 vec, float velocity)
{
	m_fptLookAt = m_fptLookAt + vec * velocity * fDT;
	m_fptCurLookAt = m_fptCurLookAt + vec * velocity * fDT;

	Vec2 fptCenter = Vec2(WINSIZEX / 2.f, WINSIZEY / 2.f);
	m_fptDiff = m_fptCurLookAt - fptCenter;
}


void CCameraManager::CalDiff()
{
	m_fAccTime += fDT;

	Vec2 fvLookDir = m_fptLookAt - m_fptPrevLookAt;

	// �ð��� �����ų� ���� ������ ũ�Ⱑ 0�̶��, �����Ѱ����� ����. �ӵ��� 0����
	if (m_fTime <= m_fAccTime || fvLookDir.Length() == 0)
	{
		m_fptCurLookAt = m_fptLookAt;
		m_fSpeed = 0.f;
	}
	else
	{
		m_fptCurLookAt = m_fptPrevLookAt + fvLookDir.Normalize() * m_fSpeed * fDT;
	}

	Vec2 fptCenter = Vec2(WINSIZEX / 2.f, WINSIZEY / 2.f);

	m_fptDiff = m_fptCurLookAt - fptCenter;
	m_fptPrevLookAt = m_fptCurLookAt;
	m_fPreSpeed = m_fSpeed;

	// ��ӵ���ŭ �����ӵ��� ������.
	m_fSpeed = m_fPreSpeed += m_fAccel * fDT;
}
