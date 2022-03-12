#include "pch.h"
#include "CBG1.h"
#include "CTexture.h"
#include "CScene.h"


CBG1::CBG1()
{
	m_pTex = CResourceManager::getInst()->LoadTexture(L"BGTex", L"texture\\1-1map.bmp");
}

CBG1::~CBG1()
{
}
void CBG1::update()
{

}

void CBG1::render(HDC hDC)
{
	int iWidth = (int)m_pTex->GetBmpWidth();
	int iHeight = (int)m_pTex->GetBmpHeight();

	Vec2 vPos = GetPos();
	vPos = CCameraManager::getInst()->GetRenderPos(vPos);
	TransparentBlt(hDC,
		0+vPos.x,
		0+vPos.y,
		iWidth, iHeight,
		m_pTex->GetDC(),
		0, 0, 
		iWidth, iHeight, 
		RGB(255,0,255));
}