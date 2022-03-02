#include "pch.h"
#include "CGameObject.h"
#include "CCollider.h"

CGameObject::CGameObject()
{
	m_pCollider = nullptr;
}

CGameObject::~CGameObject()
{
	if (nullptr != m_pCollider)
	{
		delete m_pCollider;
	}
}

void CGameObject::finalupdate()
{
	if (nullptr != m_pCollider)//충돌체가 없으면
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



