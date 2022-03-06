#include "pch.h"
#include "CTile.h"
#include "CTexture.h"
#include "CScene.h"
#include "CCollider.h"
#include "CMario.h"

CTile::CTile()
{
	//m_pTex = CResourceManager::getInst()->LoadTexture(L"TileTex", L"texture\\Tile.bmp");
	//SetScale(Vec2(32.f, 64.f));
	//CreateCollider();
	//GetCollider()->SetScale(Vec2(GetScale().x,GetScale().y));

}

CTile::~CTile()
{
}

void CTile::update()
{
}

void CTile::render(HDC hDC)
{
	//int iWidth = (int)m_pTex->GetBmpWidth();
	//int iHeight = (int)m_pTex->GetBmpHeight();

	Vec2 vPos = GetPos();
	//vPos = CCameraManager::getInst()->GetRenderPos(vPos);
	//BitBlt(hDC,
	//int(vPos.x - (float)(iWidth / 2)),
	//int(vPos.y - (float)(iHeight / 2)),
	//iWidth, iHeight,
	//m_pTex->GetDC(),
	//0, 0, SRCCOPY);

	component_render(hDC);
}




