#include "pch.h"
#include "CNumber.h"
#include "CMario.h"
#include "CTexture.h"
#include "CScene.h"


CNumber::CNumber()
{
	switch (CMario::Getlife())
	{
	case 1:m_pTex = CResourceManager::getInst()->LoadTexture(L"OneTex", L"texture\\One.bmp");
		break;
	case 2:m_pTex = CResourceManager::getInst()->LoadTexture(L"TwoTex", L"texture\\Two.bmp");
		break;
	case 3:m_pTex = CResourceManager::getInst()->LoadTexture(L"ThreeTex", L"texture\\Three.bmp");
		break;
	case 4:m_pTex = CResourceManager::getInst()->LoadTexture(L"FourTex", L"texture\\Four.bmp");
		break;
	case 5:m_pTex = CResourceManager::getInst()->LoadTexture(L"FiveTex", L"texture\\Five.bmp");
		break;
	default:m_pTex = CResourceManager::getInst()->LoadTexture(L"ZeroTex", L"texture\\Zero.bmp");
		break;
	}
}


CNumber::~CNumber()
{
}

void CNumber::update()
{
	
}

void CNumber::render(HDC hDC)
{
	int iWidth = (int)m_pTex->GetBmpWidth();
	int iHeight = (int)m_pTex->GetBmpHeight();

	Vec2 vPos = GetPos();
	vPos = CCameraManager::getInst()->GetRenderPos(vPos);
	BitBlt(hDC,
		int(vPos.x - (float)(iWidth / 2)),
		int(vPos.y - (float)(iHeight / 2)),
		iWidth, iHeight,
		m_pTex->GetDC(),
		0, 0, SRCCOPY);
}

