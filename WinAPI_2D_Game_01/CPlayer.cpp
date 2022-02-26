#include "pch.h"
#include "CPlayer.h"

#include "CSceneManager.h"
#include "CScene.h"

#include "CResourceManager.h"
#include "CPathManager.h"
#include "CKeyManager.h"
#include "CTimeManager.h"

#include "CMissile.h"
#include "CTexture.h"

CPlayer::CPlayer()
	:m_pTex(nullptr)
{
	//Texture �ε��ϱ�
	m_pTex = CResourceManager::GetInst()->LoadTexture(L"PlayerTex", L"texture\\Player.bmp");
	
}

CPlayer::~CPlayer()
{

}



void CPlayer::update()
{
	fPoint vPos = GetPos();//���������� �����غ��� ����� ����Ȱ� �ƴ�
	//�׷��Ƿ� �̵��ϰ� �ؿ� �ٽ� setPos�������

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

void CPlayer::render(HDC _dc)
{
	int iWidth = (int)m_pTex->Width(); //�ȼ��� ������ ������ bitBlt�� ������ ����(ȭ��ۿ��׸�) �� �����ϱ⶧���� ��Ʈ�� ĳ������
	int iHeight = (int)m_pTex->Height();
	
	fPoint vPos = GetPos();

	//BitBlt(_dc,
	//	int(vPos.x - (float)(iWidth / 2)),
	//	int(vPos.y - (float)(iHeight / 2)),
	//	iWidth, iHeight,
	//	m_pTex->GetDC(),
	//	0, 0, SRCCOPY);

	TransparentBlt(_dc,  //���� ������Ʈ�� �����Ƿ� ��ũ������ ���Ƿ� ���̺귯���� �߰��ؾ��Ѵ�
		int(vPos.x - (float)(iWidth / 2)),
		int(vPos.y - (float)(iHeight / 2)),
		iWidth, iHeight, 
		m_pTex->GetDC(),
		0,0,
		iWidth, iHeight, //���� ���� �»�����κ����� ���̰�
		RGB(255,0,255));
}

void CPlayer::CreateMissile()
{
	fPoint vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	//Missile Object
	CMissile* pMissile = new CMissile;
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(fPoint(25.f, 25.f));
	pMissile->SetDir(fPoint(-1.f, -7.f));

	CScene* pCurScene = CSceneManager::GetInst()->GetCurScene();
	pCurScene->AddObject(pMissile,GROUP_TYPE::DEFAULT);
}
