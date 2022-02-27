#include "pch.h"
#include "CObject.h"

#include "CCollider.h"

CObject::CObject()
	 :m_vPos{}
	, m_vScale{}
, m_pCollider(nullptr)
{
	
}
CObject::~CObject()
{
	if (nullptr != m_pCollider)
		delete m_pCollider;

}

void CObject::CreateCollider()
{
	m_pCollider = new CCollider;
	m_pCollider->m_pOwner = this;//동적할당하고 자기 자신의 주소를 콜라이더에게 알려줌 쌍방연결
}

void CObject::finalupdate()
{
	if (m_pCollider)
		m_pCollider->finalupdate();
}

void CObject::render(HDC _dc)
{
	Rectangle(_dc,
		(int)m_vPos.x - m_vScale.x / 2.f,
		(int)m_vPos.y - m_vScale.y / 2.f,
		(int)m_vPos.x + m_vScale.x / 2.f,
		(int)m_vPos.y + m_vScale.y / 2.f);

	component_render(_dc);
}

void CObject::component_render(HDC _dc)
{
	if (nullptr != m_pCollider)
	{
		m_pCollider->render(_dc);
	}
}
