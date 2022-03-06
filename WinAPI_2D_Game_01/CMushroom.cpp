#include "pch.h"
#include "CMushroom.h"
#include "CScene.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CAnimation.h"
#include "CMario.h"

float CMushroom::sDeleteCount = 0.f;

CMushroom::CMushroom()
{
	isDelete = false;

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
	if (true == isDelete)
	{
		sDeleteCount+=fDT;
	}
	if (sDeleteCount >= 0.5f)
	{
		DeleteEffect();
		sDeleteCount = 0.f;
	}
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

void CMushroom::OnCollision(CCollider* pOther)
{
	CGameObject* ppOther = pOther->GetObj();
	if (ppOther->GetName() == L"Mario")
	{
		if (pOther->GetFinalPos().y +14.f  < GetCollider()->GetFinalPos().y)
		{
			GetAnimator()->Play(L"MushroomHit");
			isDelete = true;
			GetCollider()->SetOffsetPos(Vec2(0.f, 40.f));
			Vec2 p = ppOther->GetPos();
			p.y -= 1;
			ppOther->SetPos(p);
			
			CMario* pppOther = (CMario*)ppOther;
			pppOther->SetLittleJump(true);
		}
		/*Vec2 p = GetPos();
		p.y -= 50;
		SetPos(p);*/
	}
}

void CMushroom::OnCollisionExit(CCollider* pOther)
{
}

void CMushroom::DeleteEffect()
{
	CEventManager::getInst()->EventDeleteObject(this);
}




