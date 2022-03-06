#pragma once
#include "CGameObject.h"

class CMario;

class CFoot : public CGameObject
{
	friend class CMario;
private:
	CMario* m_pOwner;
	Vec2 m_offset;
public:
	virtual void update();
	virtual void render(HDC hDC);

	void FollowOwner();
public:
	CFoot();
	~CFoot();
	virtual CFoot* Clone() { return new CFoot(*this); }
};

