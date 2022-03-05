#include "pch.h"
#include "CMario.h"
#include "CScene.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CAnimation.h"

#define DEFAULT_V 400.f
#define DEFAULTGRAV 800.f
#define MAXACC 150.f

CMario::CMario()
{
	SetName(L"Mario");
	SetPos(Vec2(300.f,300.f));
	SetScale(Vec2(32.f, 32.f));
	m_fVelocityUD = DEFAULT_V;
	m_fVelocityLR = 100;
	m_fGrav = 0.f;
	m_fAcc = 0.f;
	isFacedRight = true;
	isAir = false;
	isUpside = false;
	canJump = true;


	m_pTex = CResourceManager::getInst()->LoadTexture(L"PlayerTex", L"texture\\Animation\\Animation_Mario.bmp");
	CreateCollider();
	GetCollider()->SetScale(Vec2(GetScale().x, GetScale().y));
	GetCollider()->SetOffsetPos(Vec2(0.f, 16.f));

	CreateAnimator();
	//작은형태
	GetAnimator()->CreateAnimation(L"SmallLeftStill", m_pTex, Vec2(0.f, 64.f), Vec2(32.f, 64.f), Vec2(32.f, 0.f), 1.f, 1);
	GetAnimator()->CreateAnimation(L"SmallRightStill", m_pTex, Vec2(0.f, 0.f), Vec2(32.f, 64.f), Vec2(32.f, 0.f), 1.f, 1);

	GetAnimator()->CreateAnimation(L"SmallLeftMove", m_pTex, Vec2(32.f, 64.f), Vec2(32.f, 64.f), Vec2(32.f, 0.f), 0.1f, 3);
	GetAnimator()->CreateAnimation(L"SmallRightMove", m_pTex, Vec2(32.f, 0.f), Vec2(32.f, 64.f), Vec2(32.f, 0.f), 0.1f, 3);
	
	GetAnimator()->CreateAnimation(L"SmallLeftRun", m_pTex, Vec2(32.f, 64.f), Vec2(32.f, 64.f), Vec2(32.f, 0.f), 0.05f, 3);
	GetAnimator()->CreateAnimation(L"SmallRightRun", m_pTex, Vec2(32.f, 0.f), Vec2(32.f, 64.f), Vec2(32.f, 0.f), 0.05f, 3);

	GetAnimator()->CreateAnimation(L"SmallLeftJump", m_pTex, Vec2(160.f, 64.f), Vec2(32.f, 64.f), Vec2(32.f, 0.f), 1.f, 1);
	GetAnimator()->CreateAnimation(L"SmallRightJump", m_pTex, Vec2(160.f, 0.f), Vec2(32.f, 64.f), Vec2(32.f, 0.f), 1.f, 1);

	GetAnimator()->CreateAnimation(L"SmallLeftStop", m_pTex, Vec2(128.f, 64.f), Vec2(32.f, 64.f), Vec2(32.f, 0.f), 0.25f, 1);
	GetAnimator()->CreateAnimation(L"SmallRightStop", m_pTex, Vec2(128.f, 0.f), Vec2(32.f, 64.f), Vec2(32.f, 0.f), 0.25f, 1);

	GetAnimator()->CreateAnimation(L"SmallHit", m_pTex, Vec2(192.f, 0.f), Vec2(32.f, 64.f), Vec2(32.f, 0.f), 1.f, 1);

	GetAnimator()->CreateAnimation(L"SmallGrow", m_pTex, Vec2(0.f, 256.f), Vec2(32.f, 64.f), Vec2(32.f, 0.f), 0.3f, 3);
	//큰형태

	GetAnimator()->CreateAnimation(L"BigLeftStill", m_pTex, Vec2(0.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.5f, 2);
	GetAnimator()->CreateAnimation(L"BigRightStill", m_pTex, Vec2(0.f, 70.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.5f, 2);

	GetAnimator()->CreateAnimation(L"BigLeftMove", m_pTex, Vec2(0.f, 140.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 3);
	GetAnimator()->CreateAnimation(L"BigRightMove", m_pTex, Vec2(0.f, 210.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 3);

	GetAnimator()->CreateAnimation(L"BigLeftJump", m_pTex, Vec2(140.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 1);
	GetAnimator()->CreateAnimation(L"BigRightJump", m_pTex, Vec2(140.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 1);

	GetAnimator()->CreateAnimation(L"BigLeftStop", m_pTex, Vec2(140.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 1);
	GetAnimator()->CreateAnimation(L"BigRightStop", m_pTex, Vec2(140.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 1);

	GetAnimator()->CreateAnimation(L"BigShrink", m_pTex, Vec2(140.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 1);

	GetAnimator()->CreateAnimation(L"BigSit", m_pTex, Vec2(140.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 1);


	//꽃형태
	GetAnimator()->CreateAnimation(L"FlowerLeftStill", m_pTex, Vec2(0.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.5f, 2);
	GetAnimator()->CreateAnimation(L"FlowerRightStill", m_pTex, Vec2(0.f, 70.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.5f, 2);

	GetAnimator()->CreateAnimation(L"FlowerLeftMove", m_pTex, Vec2(0.f, 140.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 3);
	GetAnimator()->CreateAnimation(L"FlowerRightMove", m_pTex, Vec2(0.f, 210.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 3);

	GetAnimator()->CreateAnimation(L"FlowerLeftJump", m_pTex, Vec2(140.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 1);
	GetAnimator()->CreateAnimation(L"FlowerRightJump", m_pTex, Vec2(140.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 1);

	GetAnimator()->CreateAnimation(L"FlowerLeftStop", m_pTex, Vec2(140.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 1);
	GetAnimator()->CreateAnimation(L"FlowerRightStop", m_pTex, Vec2(140.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 1);

	GetAnimator()->CreateAnimation(L"FlowerShrink", m_pTex, Vec2(140.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 1);

	GetAnimator()->CreateAnimation(L"FlowerSit", m_pTex, Vec2(140.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 1);

	GetAnimator()->CreateAnimation(L"FlowerRightShoot", m_pTex, Vec2(140.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 1);
	GetAnimator()->CreateAnimation(L"FlowerLeftShoot", m_pTex, Vec2(140.f, 0.f), Vec2(70.f, 70.f), Vec2(70.f, 0.f), 0.25f, 1);

	GetAnimator()->Play(L"SmallRightStill");

	//CAnimation* pAni;
	//pAni = GetAnimator()->FindAnimation(L"SmallRightStill");
	//pAni->GetFrame(1).fptOffset = fVec2(0.f, -10.f);

	CCameraManager::getInst()->GetRenderPos(GetPos());
}

CMario::~CMario()
{
}


void CMario::update()
{
	
	m_fGrav = DEFAULTGRAV;
	Vec2 pos = GetPos();

	

	if (KEYDOWN('Z'))
	{
		CCameraManager::getInst()->SetLookAt(Vec2(500, 500));
		//CCameraManager::getInst()->SetTargetObj(this);
	}

	if (KEY(VK_LEFT))//왼키누르고있기
	{
		isFacedRight = false;
		pos.x -= (m_fVelocityLR +m_fAcc)* fDT;
		switch (m_type)
		{
		case STATUS::SMALL:
			{
			if (KEY(VK_LSHIFT)&&false == isAir)
			{
				GetAnimator()->Play(L"SmallLeftRun");
			}
			else if(true==isAir){}
			else
			{
				GetAnimator()->Play(L"SmallLeftMove");
			}
			}break;
		}		
	}
	if (KEYUP(VK_LEFT))//왼키누르다떼기
	{
		switch (m_type)
		{
		case STATUS::SMALL:
			{
				GetAnimator()->Play(L"SmallLeftStill");
			}break;
		}
	}
	if (KEY(VK_RIGHT))//오른키누르고있기
	{
		isFacedRight = true;
		pos.x += (m_fVelocityLR + m_fAcc) * fDT;
		switch (m_type)
		{
		case STATUS::SMALL:
		{
			if (KEY(VK_LSHIFT) && false == isAir)
			{
				GetAnimator()->Play(L"SmallRightRun");
			}
			else if (true == isAir) {}
			else
			{
				GetAnimator()->Play(L"SmallRightMove");
			}
			//if (KEYUP(VK_RIGHT) && KEY(VK_LEFT))//TODO: 반대로갈때 모션 구현
			//{
			//	GetAnimator()->Play(L"SmallLeftStop"); 
			//}
		}break;
		}
	}
	if (KEYUP(VK_RIGHT))//오른키누르다떼기
	{
		switch (m_type)
		{
		case STATUS::SMALL:
		{
			GetAnimator()->Play(L"SmallRightStill");
		}break;
		}
	}

	if (KEY(VK_LSHIFT))//속도올리기
	{
		if(m_fAcc<MAXACC)
		m_fAcc += 200*fDT;
	}
	if (KEYUP(VK_LSHIFT))
	{
		m_fAcc = 0;
	}

	if (KEYDOWN(VK_UP) && true==canJump)//점프
	{
		canJump = false;
		isAir = true;
		isUpside = true;
		switch (m_type)
		{
		case STATUS::SMALL:
		{
			if(true==isFacedRight)
				GetAnimator()->Play(L"SmallRightJump");
			else
				GetAnimator()->Play(L"SmallLeftJump");
		}break;
		}
	}

	if (true == isAir && canJump==false)
	{
		if (KEY(VK_LEFT))
			GetAnimator()->Play(L"SmallLeftJump");
		else if (KEY(VK_RIGHT))
			GetAnimator()->Play(L"SmallRightJump");
		if (m_fVelocityUD <= 0)
		{
			isUpside = false;
		}

		if (true == isUpside)
		{
			m_fVelocityUD -= m_fGrav * fDT;
			pos.y -= m_fVelocityUD * fDT;
		}
		else if (false == isUpside)
		{
			m_fVelocityUD += m_fGrav * fDT;
			pos.y += m_fVelocityUD * fDT;
		}
	}
	if (KEY(VK_DOWN))
	{
		//TODO: 충돌체 사이즈 앉은만큼 작아지도록 구현
		switch (m_type)
		{
		case STATUS::LARGE:
		{
			GetAnimator()->Play(L"BigSit");
		}break;
		case STATUS::FLOWER:
		{
			GetAnimator()->Play(L"FlowerSit");
		}break;
		}
	}

	SetPos(pos);

	GetAnimator()->update();
}

void CMario::render(HDC hDC)
{
	//int iWidth = (int)m_pTex->GetBmpWidth();
	//int iHeight = (int)m_pTex->GetBmpHeight();

	//Vec2 vPos = GetPos();

	component_render(hDC);
}


void CMario::OnCollisionEnter(CCollider* _pOther)
{
	CGameObject* pOther = _pOther->GetObj();
	if (pOther->GetName() == L"Tile")
	{
		canJump = true;
		isAir = false;
		m_fVelocityUD = DEFAULT_V;
	}
	Vec2 t = CCameraManager::getInst()->GetLook();
	if (pOther->GetName() == L"MidLine"&&true==isFacedRight)
	{
		Vec2 p = pOther->GetPos();
		p.x += 2;
		pOther->SetPos(p);
		t.x += 2;
		CCameraManager::getInst()->SetLookAt(t);
	}
}

void CMario::OnCollisionExit(CCollider* _pOther)
{
	//isAir = true;
	//canJump = false;
}

void CMario::OnCollision(CCollider* _pOther)
{
	//CGameObject* pOther = _pOther->GetObj();
	//if (pOther->GetName() == L"Tile")
	//{
	//	canJump = true;
	//	isAir = false;
	//	m_fVelocityUD = DEFAULT_V;
	//}
}

//void CMario::OnCollisionNone(CCollider* _pOther)
//{
//	isAir = true;
//}
