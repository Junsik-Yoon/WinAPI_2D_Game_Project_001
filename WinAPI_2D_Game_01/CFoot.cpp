#include "pch.h"
#include "CFoot.h"
#include "CMario.h"
#include "CCollider.h"

CFoot::CFoot()
{
	m_pOwner = nullptr;
	m_offset = {};
	CreateCollider();
	GetCollider()->SetScale(Vec2((float)GetScale().x, (float)GetScale().y));
}

CFoot::~CFoot()
{
}

void CFoot::update()
{
	FollowOwner();
}

void CFoot::render(HDC hDC)
{
	component_render(hDC);
}

void CFoot::FollowOwner()
{
	Vec2 ownerP = m_pOwner->GetPos();
	SetPos(ownerP);
}


