#include "pch.h"
#include "CMushroom.h"
#include "CScene.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CAnimation.h"

CMushroom::CMushroom()
{
	m_pTex = CResourceManager::getInst()->LoadTexture(L"MushroomTex", L"texture\\Animation\\Animation_Mushroom.bmp");
	CreateCollider();
	GetCollider()->SetScale(Vec2(32.f, 32.f));
	GetCollider()->SetOffsetPos(Vec2(GetScale().x, GetScale().y));

	CreateAnimator();
	GetAnimator()->CreateAnimation(L"MushroomMove", m_pTex, Vec2(0.f, 0.f), Vec2(32.f, 32.f), Vec2(32.f, 0.f), 0.5f, 2);
	GetAnimator()->CreateAnimation(L"MushroomHit", m_pTex, Vec2(64.f, 0.f), Vec2(32.f, 32.f), Vec2(32.f, 0.f), 1.f, 1);
	GetAnimator()->Play(L"MushroomMove");
	CCameraManager::getInst()->GetRenderPos(GetPos());
}

CMushroom::~CMushroom()
{

}

void CMushroom::update()
{
	
	Vec2 vPos = GetPos();
	vPos.x -= 10 * fDT;
	SetPos(vPos);

	GetAnimator()->update();
}

void CMushroom::render(HDC hDC)
{
	component_render(hDC);
}

void CMushroom::OnCollisionEnter(CCollider* pOther)
{
}




