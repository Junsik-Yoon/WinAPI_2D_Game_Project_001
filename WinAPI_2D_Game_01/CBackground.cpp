#include "pch.h"
#include "CBackground.h"
#include "CTexture.h"
#include "CScene.h"


CBackground::CBackground()
{
	m_pTex = CResourceManager::getInst()->LoadTexture(L"BGTex", L"texture\\Background.bmp");
}

CBackground::~CBackground()
{
}
void CBackground::update()
{
}

void CBackground::render(HDC hDC)
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


