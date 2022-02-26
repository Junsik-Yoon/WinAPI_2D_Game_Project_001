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
	//Texture 로딩하기
	m_pTex = CResourceManager::GetInst()->LoadTexture(L"PlayerTex", L"texture\\Player.bmp");
	
}

CPlayer::~CPlayer()
{

}



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

void CPlayer::render(HDC _dc)
{
	int iWidth = (int)m_pTex->Width(); //픽셀은 음수가 없지만 bitBlt에 들어갈떄는 음수(화면밖에그림) 이 가능하기때문에 인트로 캐스팅함
	int iHeight = (int)m_pTex->Height();
	
	fPoint vPos = GetPos();

	//BitBlt(_dc,
	//	int(vPos.x - (float)(iWidth / 2)),
	//	int(vPos.y - (float)(iHeight / 2)),
	//	iWidth, iHeight,
	//	m_pTex->GetDC(),
	//	0, 0, SRCCOPY);

	TransparentBlt(_dc,  //실제 구현파트가 없으므로 링크에러가 나므로 라이브러리를 추가해야한다
		int(vPos.x - (float)(iWidth / 2)),
		int(vPos.y - (float)(iHeight / 2)),
		iWidth, iHeight, 
		m_pTex->GetDC(),
		0,0,
		iWidth, iHeight, //원본 내의 좌상단으로부터의 길이값
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
