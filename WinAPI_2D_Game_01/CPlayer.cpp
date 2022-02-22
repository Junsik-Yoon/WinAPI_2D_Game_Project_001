#include "pch.h"
#include "CPlayer.h"

#include "CSceneManager.h"
#include "CScene.h"

#include "CKeyManager.h"
#include "CTimeManager.h"

#include "CMissile.h"

void CPlayer::update()
{
	fPoint vPos = GetPos();//지역변수를 수정해봤자 멤버가 변경된게 아님
	//그러므로 이동하고 밑에 다시 setPos해줘야함

	if (KEY_HOLD(KEY::W))
	{
		vPos.y -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::S))
	{
		vPos.y += 200.f * fDT;
	}
	if (KEY_HOLD(KEY::A))
	{
		vPos.x -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::D))
	{
		vPos.x += 200.f * fDT;
	}
	if (KEY_TAP(KEY::SPACE))
	{
		CreateMissile();
	}

	SetPos(vPos); 
}

void CPlayer::CreateMissile()
{
	fPoint vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	//Missile Object
	CMissile* pMissile = new CMissile;
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(fPoint(25.f, 25.f));
	CScene* pCurScene = CSceneManager::GetInst()->GetCurScene();
	pCurScene->AddObject(pMissile,GROUP_TYPE::DEFAULT);
}
