#include "pch.h"
#include "CInfo.h"
#include "CTexture.h"
#include "CScene.h"

CInfo::CInfo()
{
	
	m_pTex = CResourceManager::getInst()->LoadTexture(L"InfoTex", L"texture\\Info.bmp");
}

CInfo::~CInfo()
{
}


void CInfo::update()
{
}

void CInfo::render(HDC hDC)
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

