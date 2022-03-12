#include "pch.h"
#include "CLou.h"
#include "CScene.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CAnimation.h"

CLou::CLou()
{
	SetName(L"Lou");
	m_pTex= CResourceManager::getInst()->LoadTexture(L"PlayerTex", L"texture\\Animation\\Animation_Lou.bmp");
	CreateCollider();
	GetCollider()->SetScale(Vec2(GetScale().x, GetScale().y));
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));

	CreateAnimator();
	//¿Ê ÀÔÀ½
	GetAnimator()->CreateAnimation(L"Idle_Right", m_pTex, Vec2(0.f, 0.f), Vec2(106.f, 106.f), Vec2(106.f, 0.f), 0.5f, 6);
	GetAnimator()->CreateAnimation(L"Idle_Left", m_pTex, Vec2(0.f, 106.f), Vec2(106.f, 106.f), Vec2(106.f, 0.f), 0.5f, 6);

	GetAnimator()->CreateAnimation(L"Move_Right", m_pTex, Vec2(0.f, 212.f), Vec2(106.f, 106.f), Vec2(106.f, 0.f), 0.2f, 6);
	GetAnimator()->CreateAnimation(L"Move_Left", m_pTex, Vec2(0.f, 318.f), Vec2(106.f, 106.f), Vec2(106.f, 0.f), 0.2f, 6);
	//Å»ÀÇ

	GetAnimator()->Play(L"Idle_Right");

	CCameraManager::getInst()->GetRenderPos(GetPos());

}

CLou::~CLou()
{
}

void CLou::OnCollisionEnter(CCollider* _pOther)
{
}

void CLou::OnCollision(CCollider* _pOther)
{
}

void CLou::OnCollisionExit(CCollider* _pOther)
{
}

void CLou::update()
{
	Vec2 pos = GetPos();

	if (KEY(VK_LEFT))//¿ÞÅ°´©¸£´Ù¶¼±â
	{
		pos.x -= 100 * fDT;
		GetAnimator()->Play(L"Move_Left");
	}

	if (KEY(VK_RIGHT) )//¿À¸¥Å°´©¸£´Ù¶¼±â
	{
		pos.x += 100 * fDT;
		GetAnimator()->Play(L"Move_Right");
	}

	SetPos(pos);

	GetAnimator()->update();
}

void CLou::render(HDC hDC)
{
	component_render(hDC);
}


