#include "pch.h"
#include "CTile.h"
#include "CTexture.h"

CTile::CTile()
{
	m_pTex = nullptr;
	m_iIdx = 0;
	SetScale(Vec2(SIZE_TILE, SIZE_TILE));
}

CTile::~CTile()
{
}



void CTile::update()
{
}

void CTile::render(HDC hDC)
{
	if (nullptr == m_pTex)
	{
		return;
	}
	UINT iWidth = m_pTex->GetBmpWidth();
	UINT iHeight = m_pTex->GetBmpHeight();

	UINT iMaxRow = iHeight / SIZE_TILE;
	UINT iMaxCol = iWidth / SIZE_TILE;
	UINT iCurRow = (m_iIdx / iMaxCol) % iMaxRow;
	UINT iCurCol = (m_iIdx % iMaxCol);

	Vec2 fptRenderPos = CCameraManager::getInst()->GetRenderPos(GetPos());
	Vec2 fptScale = GetScale();

	BitBlt(hDC,
		(int)(fptRenderPos.x),
		(int)(fptRenderPos.y),
		(int)(fptScale.x),
		(int)(fptScale.y),
		m_pTex->GetDC(),
		iCurCol * SIZE_TILE,
		iCurRow * SIZE_TILE,
		SRCCOPY);
		

	//Rectangle(hDC,
	//	(int)(fptRenderPos.x),
	//	(int)(fptRenderPos.y),
	//	(int)(fptRenderPos.x + fptScale.x),
	//	(int)(fptRenderPos.y + fptScale.y));
}



void CTile::Save(FILE* pFile)
{
	fwrite(&m_iIdx, sizeof(int), 1, pFile);
}

void CTile::Load(FILE* pFile)
{
	fread(&m_iIdx, sizeof(int), 1, pFile);
}

