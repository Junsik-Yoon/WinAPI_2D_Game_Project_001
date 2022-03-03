#include "pch.h"
#include "CGameObject.h"
#include "CCollider.h"
#include "CAnimation.h"
#include "CAnimator.h"

CGameObject::CGameObject()
{
	m_pCollider = nullptr;
	m_bAlive = true;
	m_strName = L"";
}

CGameObject::CGameObject(const CGameObject& other)
{
	m_strName = other.m_strName;
	m_fptPos = other.m_fptPos;
	m_fptScale = other.m_fptScale;
	m_bAlive = true;
	m_pCollider = nullptr;
	if (nullptr != other.m_pCollider)//�����Ϸ����ϴ� ��ü�� �浹ü�� �ִ°��
	{
		m_pCollider = new CCollider(*other.m_pCollider);
		m_pCollider->m_pOwner=this;
	}
	if (nullptr != other.m_pAnimator)
	{
		m_pAnimator = new CAnimator(*other.m_pAnimator);
		m_pAnimator->m_pOwner = this;
	}
}

CGameObject::~CGameObject()
{
	if (nullptr != m_pCollider)
	{
		delete m_pCollider;
	}
	if (nullptr != m_pAnimator)
	{
		delete m_pAnimator;
	}
}

void CGameObject::finalupdate()
{
	if (nullptr != m_pCollider)//�浹ü�� ������
	{
		m_pCollider->finalupdate();
	}
}

void CGameObject::render(HDC hDC)
{
	component_render(hDC);
}

void CGameObject::component_render(HDC hDC)
{
	if (nullptr != m_pAnimator)
	{
		m_pAnimator->render(hDC);
	}
	if (nullptr != m_pCollider)
	{
		m_pCollider->render(hDC);
	}
	
}

void CGameObject::CreateCollider()
{
	m_pCollider = new CCollider();
	m_pCollider->m_pOwner = this;
}

void CGameObject::CreateAnimator()
{
	m_pAnimator = new CAnimator();
	m_pAnimator->m_pOwner = this;
}



