#pragma once
#include "CGameObject.h"
class CMonster : public CGameObject
{
private:
	fVec2 m_fPtCenterPos;
	float m_fVelocity;
	float m_fDistance;
	bool m_bIsUpDir = true;

public:
	CMonster();
	~CMonster();
	virtual void update();
	virtual void render(HDC hDC);

	void SetCenterPos(fVec2 point) { m_fPtCenterPos = point; }
	fVec2 GetCenterPos(){ return m_fPtCenterPos; }

};

