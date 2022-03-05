#pragma once
#include "CGameObject.h"


class CMidLine : public CGameObject
{
public:

	virtual void update();
	virtual void render(HDC hDC);


public:
	CMidLine();
	~CMidLine();
	virtual CMidLine* Clone() { return new CMidLine(*this); }


};

