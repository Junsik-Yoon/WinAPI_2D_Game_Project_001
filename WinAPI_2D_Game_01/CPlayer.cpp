#include "pch.h"
#include "CPlayer.h"
#include "CMissile.h"
#include "CScene.h"
#define DEFAULT_V 500
CPlayer::CPlayer()
{
	SetPos(fVec2(300, 300));
	SetScale(fVec2(30, 50));
	m_velocity = DEFAULT_V;
	hp = 100;
	m_grav = 0;
	m_acc = 0;
	isAir = false;
	isUpside = false;
}

CPlayer::~CPlayer()
{
}

void CPlayer::update()
{
	fVec2 vPos = GetPos();
	
	m_grav = 300.f;
	
	
	if (KEYDOWN(VK_UP))
	{
		isAir = true;
		isUpside = true;
	}
	if (true == isAir)
	{
		if (m_velocity <= 0)
		{
			isUpside = false;
		}

		if (true==isUpside)
		{
			m_velocity -= m_grav * fDT;
			vPos.y -= m_velocity * fDT;
		}
		else if (false==isUpside)
		{
			m_velocity += m_grav * fDT;
			vPos.y += m_velocity * fDT;
		}
		
		if (vPos.y >= WINSIZEY-65-GetScale().y)
		{
			isAir = false;
			m_velocity = 500;
		}
	}
	//if (KEY(VK_DOWN) && KEYDOWN(VK_SPACE))
	if(KEYDOWN(VK_DOWN))
	{
		//만약 1층이 아니라면 아래층으로 가도록 짜기
		//if(vPos.y>)
		vPos.y += m_velocity;// *DT;
	}
	if (KEY(VK_LEFT))
	{
		vPos.x -= m_velocity * DT;
	}
	if (KEY(VK_RIGHT))
	{
		vPos.x += m_velocity * DT;
	}

	if (KEYDOWN(VK_SPACE))
	{
		CreateMissile();
	}

	SetPos(vPos);
}

void CPlayer::render(HDC hDC)
{
	Rectangle(hDC, GetPos().x - GetScale().x,
		GetPos().y - GetScale().y,
		GetPos().x + GetScale().x,
		GetPos().y + GetScale().y);
	Rectangle(hDC, GetPos().x,
		GetPos().y - GetScale().y / 4,
		GetPos().x + GetScale().x*2,
		GetPos().y + GetScale().y / 4);
}

void CPlayer::CreateMissile()
{
	fVec2 fptMissilePos = GetPos();
	fptMissilePos.x += GetScale().x*2;

	CMissile* pMissile = new CMissile;
	pMissile->SetPos(fptMissilePos);
	pMissile->SetScale(fVec2(25.f, 25.f));
	pMissile->SetDir(fVec2(1,0));

	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMissile, GROUP_GAMEOBJ::MISSILE); //불완전한 코드 이벤트 동기화가 안일어남


}
