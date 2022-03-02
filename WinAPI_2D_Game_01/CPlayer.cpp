#include "pch.h"
#include "CPlayer.h"
#include "CMissile.h"
#include "CScene.h"
#include "CTexture.h"
#include "CCollider.h"

CPlayer::CPlayer()
{
	SetPos(fVec2(300, 300));
	SetScale(fVec2(50, 50));
	m_velocity = 200;

	m_pTex = CResourceManager::getInst()->LoadTexture(L"PlayerTex", L"texture\\Player.bmp");
	CreateCollider();
	GetCollider()->SetScale(fVec2(40.f, 40.f));
	GetCollider()->SetOffset(fVec2(0.f, 8.f));
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

	int width = m_pTex->GetBmpWidth();
	int height = m_pTex->GetBmpHeight();

	//BitBlt(hDC, (int)GetPos().x - width / 2.f,
	//	(int)GetPos().y - height / 2.f,
	//	width, height,
	//	m_pTex->GetDC(),
	//	0, 0,
	//	SRCCOPY);//�����ѿ����� �ȱ׸����ϱ����� bitblt���
	//transparentblt������
	TransparentBlt(hDC,
		(int)(GetPos().x - width / 2.f),
		(int)(GetPos().y - height / 2.f),
		width, height,
		m_pTex->GetDC(),
		0, 0, width, height,
		RGB(255, 0, 255));

	component_render(hDC);
}

void CPlayer::CreateMissile()
{
	fVec2 fptMissilePos = GetPos();
	fptMissilePos.x += GetScale().x / 2.f;

	CMissile* pMissile = new CMissile;
	pMissile->SetPos(fptMissilePos);
	pMissile->SetDir(fVec2(1.f, 1.f));

	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMissile, GROUP_GAMEOBJ::MISSILE); //�ҿ����� �ڵ� �̺�Ʈ ����ȭ�� ���Ͼ
}

void CPlayer::OnCollision(CCollider* pOther)
{
}

void CPlayer::OnCollisionEnter(CCollider* pOther)
{
	fVec2 pos = GetPos();
	pos.x -= 100;
	SetPos(pos);

}

void CPlayer::OnCollisionExit(CCollider* pOther)
{
}
