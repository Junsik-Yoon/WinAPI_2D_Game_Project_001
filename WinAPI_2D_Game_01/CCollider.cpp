#include "pch.h"
#include "CCollider.h"
#include "CGameObject.h"

UINT CCollider::s_iID = 0;

CCollider::CCollider()
{
	m_pOwner = nullptr;
	m_iID = s_iID++;
	iCollCount = 0;
}
CCollider::CCollider(const CCollider& other)
{
	m_pOwner = nullptr;
	m_fptOffset=other.m_fptOffset;
	m_fptScale = other.m_fptScale;
	m_iID = s_iID++;
	iCollCount = other.iCollCount;
}

CCollider::~CCollider()
{
}

void CCollider::finalupdate()
{
	fVec2 fptObjPos = m_pOwner->GetPos();
	m_fptFinalPos = fptObjPos+m_fptOffset;
}

void CCollider::render(HDC hDC)
{
	TYPE_PEN pen = TYPE_PEN::GREEN;
	if (iCollCount)
	{
		pen = TYPE_PEN::RED;
	}

	SelectGDI pPen(hDC,pen);
	SelectGDI pBrush(hDC, TYPE_BRUSH::HOLLOW);
	
	Rectangle(hDC,
		(int)m_fptFinalPos.x - m_fptScale.x / 2.f,
		(int)m_fptFinalPos.y - m_fptScale.y / 2.f,
		(int)m_fptFinalPos.x + m_fptScale.x / 2.f,
		(int)m_fptFinalPos.y + m_fptScale.y / 2.f);
		


}

void CCollider::OnCollision(CCollider* pOther)
{
	m_pOwner->OnCollision(pOther);
}

void CCollider::OnCollisionEnter(CCollider* pOther)
{
	m_pOwner->OnCollisionEnter(pOther);
	iCollCount++;
}

void CCollider::OnCollisionExit(CCollider* pOther)
{
	m_pOwner->OnCollisionExit(pOther); 
	iCollCount--;
}
