#include "pch.h"
#include "CCollider.h"

#include "CObject.h"
#include "CCore.h"
#include "SelectGDI.h"

UINT CCollider::g_iNextId = 0;

CCollider::CCollider()
	:m_pOwner(nullptr)
	,m_iId(g_iNextId++)//충돌체 생성시 id값을 static멤버로 받고 후위연산자로 ++시킴
	,m_iCol(0)
{
}

CCollider::CCollider(const CCollider& _original)
	: m_pOwner(nullptr),
		m_vOffsetPos(_original.m_vOffsetPos),
		m_vScale(_original.m_vScale),
		m_iId(g_iNextId++)
{

}

CCollider::~CCollider()
{
}

void CCollider::finalupdate()
{
	//Object위치를 따라간다
	Vec2 vObjectPos = m_pOwner->GetPos();
	m_vFinalPos = vObjectPos + m_vOffsetPos;

	assert(0 <= m_iCol);//만에하나 어떤 오류나 실수로 충돌카운트가 0이하로 내려갈 때
}

void CCollider::render(HDC _dc)
{
	PEN_TYPE ePen = PEN_TYPE::GREEN;

	if (m_iCol)
		ePen = PEN_TYPE::RED;

	SelectGDI pTemp(_dc,ePen);
	SelectGDI bTemp(_dc, BRUSH_TYPE::HOLLOW);

	Rectangle(_dc
		,(int)m_vFinalPos.x - m_vScale.x / 2.f
		,(int)m_vFinalPos.y - m_vScale.y / 2.f
		,(int)m_vFinalPos.x + m_vScale.y / 2.f
		,(int)m_vFinalPos.y + m_vScale.y / 2.f);

}

void CCollider::OnCollision(CCollider* _pOther)
{
	m_pOwner->OnCollision(_pOther);
}

void CCollider::OnCollisionEnter(CCollider* _pOther)
{
	++m_iCol;
	m_pOwner->OnCollisionEnter(_pOther);
}

void CCollider::OnCollisionExit(CCollider* _pOther)
{
	--m_iCol;
	m_pOwner->OnCollisionExit(_pOther);
}


