#pragma once
#include "CGameObject.h"
class CMonster : public CGameObject
{
private:
	fPoint m_fPtCenterPos;
	float m_fVelocity;
	float m_fDistance;
	bool m_bIsUpDir = true;

public:
	CMonster();
	~CMonster();
	virtual void update();
	virtual void render(HDC hDC);

	void SetCenterPos(fPoint point) { m_fPtCenterPos = point; }
	fPoint GetCenterPos(){ return m_fPtCenterPos; }

};

