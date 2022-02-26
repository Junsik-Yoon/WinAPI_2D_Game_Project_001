#include "pch.h"
#include "CPlayer.h"
#include "CMissile.h"
#include "CScene.h"
#include "CTexture.h"

CPlayer::CPlayer()
{
	SetPos(fPoint(300, 300));
	SetScale(fPoint(50, 50));
	m_velocity = 200;

	m_pTex = CResourceManager::getInst()->LoadTexture(L"PlayerTex", L"texture\\Player.bmp");
}

CPlayer::~CPlayer()
{
}

void CPlayer::update()
{
	fPoint vPos = GetPos();

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

	int width = m_pTex->GetBmpWidth();
	int height = m_pTex->GetBmpHeight();

	//BitBlt(hDC, (int)GetPos().x - width / 2.f,
	//	(int)GetPos().y - height / 2.f,
	//	width, height,
	//	m_pTex->GetDC(),
	//	0, 0,
	//	SRCCOPY);//투명한영역을 안그리게하기위해 bitblt대신
	//transparentblt를쓴다
	TransparentBlt(hDC,
		(int)(GetPos().x - width / 2.f),
		(int)(GetPos().y - height / 2.f),
		width, height,
		m_pTex->GetDC(),
		0, 0, width, height,
		RGB(255, 0, 255));

	/*Rectangle(hDC, GetPos().x - GetScale().x,
		GetPos().y - GetScale().y,
		GetPos().x + GetScale().x,
		GetPos().y + GetScale().y);*/
}

void CPlayer::CreateMissile()
{
	fPoint fptMissilePos = GetPos();
	fptMissilePos.x += GetScale().x / 2.f;

	CMissile* pMissile = new CMissile;
	pMissile->SetPos(fptMissilePos);
	pMissile->SetDir(fVec2(1.f, 0.f));

	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMissile, GROUP_GAMEOBJ::MISSILE); //불완전한 코드 이벤트 동기화가 안일어남
}
