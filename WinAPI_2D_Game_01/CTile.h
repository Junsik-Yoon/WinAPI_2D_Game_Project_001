#pragma once

#include "CGameObject.h"

class CTexture;

class CTile : public CGameObject
{
public:
	enum class TYPE
	{
		GROUND,
		WALL,
		DOOR,
		SIZE,
	};

private:
	CTexture* m_pTex;
	int m_iIdx;
	//int m_pCollider; //충돌체가있다면
public:
	const static int SIZE_TILE = 32;
public:
	virtual void update();
	virtual void render(HDC hDC);

public:
	void SetTexture(CTexture* pTex) {m_pTex = pTex;}
	void SetTileIdx(int idx) { m_iIdx = idx; }

	virtual void Save(FILE* pFile);
	virtual void Load(FILE* pFile);

public:
	CTile();
	virtual ~CTile();
	virtual CTile* Clone() { return new CTile(*this); }

};

