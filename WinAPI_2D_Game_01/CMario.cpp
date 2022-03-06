#include "pch.h"
#include "CMario.h"
#include "CScene.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CAnimation.h"
#include "CFoot.h"

#define DEFAULT_V 400.f
#define DEFAULTGRAV 800.f
#define MAXACC 150.f
#define JUMPBOOST 1.7f
#define DEFAULT_LITTLE_V 15.f
#define DEFAULT_LITTLEGRAV 100.f

float CMario::sCountTime = 0.f;
float CMario::sCountTime2 = 0.f;

CMario::CMario()
{
	SetName(L"Mario");
	SetPos(Vec2(300.f,300.f));
	SetScale(Vec2(32.f, 32.f));
	m_fVelocityUD = DEFAULT_V;
	m_fLittleVel = DEFAULT_LITTLE_V;
	m_fVelocityLR = 150;
	m_fGrav = 0.f;
	m_fAcc = 0.f;
	isFacedRight = true;
	isAir = false;
	isUpside = false;
	canJump = true;

	isLittleJump = false;

	life = 3;

	isBoost = false;
	jumpBoost = 0.f;


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

	CreateFoot();
	

	CCameraManager::getInst()->GetRenderPos(GetPos());
}

CMario::~CMario()
{
}


void CMario::CreateFoot()
{
	Vec2 vPos = GetPos();
	vPos.y += GetScale().y * 2;

	CFoot* pFoot = new CFoot();
	pFoot->SetPos(vPos);
	pFoot->SetScale(Vec2(10.f, 10.f));
	pFoot->SetName(L"Foot");

	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pFoot, GROUP_GAMEOBJ::COLLIDER);

	pFoot->m_pOwner = this;
}

void CMario::update()
{
	//m_foot->FollowOwner();

	m_fGrav = DEFAULTGRAV;

	Vec2 pos = GetPos();

	
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

	if (KEY(VK_LSHIFT)&&false==isAir&&false==isLittleJump)//속도올리기
	{
		if(m_fAcc<MAXACC)
		m_fAcc += 200*fDT;
	}
	if (KEYUP(VK_LSHIFT))
	{
		m_fAcc = 0;
	}

	if (KEY(VK_UP))//강점프
		//TODO: 바닥에 닿을때까지 위키를 누르고있으면 부스트가 최대로된다
	{
		if (false == isBoost)
		{
			sCountTime += fDT;
			if (sCountTime >= 0.13f)
			{
				isBoost = true;
				jumpBoost += JUMPBOOST;
				sCountTime = 0.f;
			}
		}
	}
	if (true == isBoost)//TODO:위키를 계속 누르면 문제가 생길듯?
	{
		sCountTime2 += fDT;
		if (sCountTime2 >= 2.f)
		{
			isBoost = false;
			jumpBoost = 0;
			sCountTime2 = 0.f;
		}
	}
	if (KEYDOWN(VK_UP) && true==canJump&&false == isLittleJump)//약점프
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
			m_fVelocityUD -= m_fGrav  * fDT;
			if(jumpBoost>0.f)
				pos.y -= m_fVelocityUD * jumpBoost * fDT;
			else
				pos.y -= m_fVelocityUD  * fDT;
		}
		else if (false == isUpside)
		{
			m_fVelocityUD += m_fGrav  * fDT;
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

	if (true == isLittleJump)
	{
		if (m_fLittleVel <= 0)
		{
			isUpside = false;
		}

		if (true == isUpside)
		{
			m_fLittleVel -= DEFAULT_LITTLEGRAV * fDT;
			pos.y -= m_fLittleVel * fDT;
		}
		else if (false == isUpside)
		{
			m_fLittleVel += DEFAULT_LITTLEGRAV * fDT;
			pos.y += m_fLittleVel * fDT;
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
		isLittleJump = false;
		canJump = true;
		isAir = false;
		m_fVelocityUD = DEFAULT_V;
		m_fLittleVel = DEFAULT_LITTLE_V;

		isBoost = false;
		jumpBoost = 0;
		sCountTime2 = 0.f;
	}

	if (pOther->GetName() == L"Mushroom")
	{
		//Vec2 p = GetPos();
		//if (_pOther->GetFinalPos().y> GetCollider()->GetFinalPos().y + 10.f)
		//{
		//	p.y -= 50;
		//}
		//SetPos(p);
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
	if (pOther->GetName() == L"FrontLine" && false == isFacedRight)
	{
		isAir = false;
		Vec2 p = GetPos();
		p.x += 2;
		SetPos(p);
		
	}

}

void CMario::OnCollisionExit(CCollider* _pOther)
{
	CGameObject* pOther = _pOther->GetObj();
	if (pOther->GetName() == L"Tile")
	{
		isAir = true;
		canJump = false;
	}
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
	//CGameObject* pOther = _pOther->GetObj();
	//if (pOther->GetName() == L"Tile")
	//{
	//	Vec2 p = GetPos();
	//	p.y -= 1;
	//	SetPos(p);
	//}
	CGameObject* pOther = _pOther->GetObj();
	if (pOther->GetName() == L"Mushroom")
	{
		if (_pOther->GetFinalPos().y + 10.f < GetCollider()->GetFinalPos().y)
		{
			CEventManager::getInst()->EventDeleteObject(pOther);
		}
		/*Vec2 p = GetPos();
		p.y -= 50;
		SetPos(p);*/
	}
}

//void CMario::OnCollisionNone(CCollider* _pOther)
//{
//	isAir = true;
//}
