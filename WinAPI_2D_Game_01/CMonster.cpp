#include "pch.h"
#include "CMonster.h"
#include "CMissile.h"
#include "CScene.h"

CMonster::CMonster()
{
	SetScale(fVec2(50, 150));
	m_fVelocity = 200;
	m_fDistance = 250;
	m_bIsUpDir = true;
	hp = 100;
	
}

CMonster::~CMonster()
{
}

void CMonster::update()
{
	fVec2 vPos = GetPos();
	
	if (m_bIsUpDir)
	{
		vPos.y -= m_fVelocity * DT;
		if (vPos.y < m_fPtCenterPos.y-m_fDistance)
		{
			m_bIsUpDir = false;
			MCreateMissile();
			
		}
	}
	else
	{
		vPos.y += m_fVelocity * DT;
		if (vPos.y > m_fPtCenterPos.y+ m_fDistance)
		{
			m_bIsUpDir = true;
			MCreateMissile();
		}
	}
	if ((int)vPos.y == 200.f || (int)vPos.y == 300.f || (int)vPos.y == 400.f || (int)vPos.y == 500.f || (int)vPos.y == 600.f)
	{
		MCreateMissile();
	}

	SetPos(vPos);
}

void CMonster::render(HDC hDC)
{
	Rectangle(hDC, GetPos().x - GetScale().x,
		GetPos().y - GetScale().y,
		GetPos().x + GetScale().x,
		GetPos().y + GetScale().y);
}

void CMonster::MCreateMissile()
{
	fVec2 fptMissilePos = GetPos();
	fptMissilePos.x -= GetScale().x * 2;

	CMissile* pMMissile = new CMissile;
	pMMissile->SetPos(fptMissilePos);
	pMMissile->SetScale(fVec2(50.f, 50.f));
	pMMissile->SetDir(fVec2(-1, -1));

	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMMissile, GROUP_GAMEOBJ::MISSILE); //불완전한 코드 이벤트 동기화가 안일어남

}
