#include "pch.h"
#include "CPlayer.h"
#include "CMissile.h"
#include "CScene.h"

CPlayer::CPlayer()
{
	SetPos(fVec2(300, 300));
	SetScale(fVec2(50, 50));
	m_velocity = 200;
}

CPlayer::~CPlayer()
{
}

void CPlayer::update()
{
	fVec2 vPos = GetPos();

	if (KEY(VK_UP))
	{
		vPos.y -= m_velocity * DT;
	}
	if (KEY(VK_DOWN))
	{
		vPos.y += m_velocity * DT;
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
}

void CPlayer::CreateMissile()
{
	fVec2 fptMissilePos = GetPos();
	fptMissilePos.x += GetScale().x / 2.f;

	CMissile* pMissile = new CMissile;
	pMissile->SetPos(fptMissilePos);
	pMissile->SetScale(fVec2(25.f, 25.f));
	pMissile->SetDir(fVec2(cos(3.14/1),sin(3.14/1)));

	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMissile, GROUP_GAMEOBJ::MISSILE); //불완전한 코드 이벤트 동기화가 안일어남

	//대각선미사일

	CMissile* pMissile2 = new CMissile;
	pMissile2->SetPos(fptMissilePos);
	pMissile2->SetDir(fVec2(WINSIZEX - fptMissilePos.x, 0 - fptMissilePos.y));;
	
	pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMissile2, GROUP_GAMEOBJ::MISSILE); //불완전한 코드 이벤트 동기화가 안일어남


}
