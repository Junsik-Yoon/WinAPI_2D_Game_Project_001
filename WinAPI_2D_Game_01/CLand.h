#pragma once
#include "CGameObject.h"
class CLand :  public CGameObject
{
private:
	fVec2 fScale;
	fVec2 fPos;


public:
	void update();
	void render(HDC hDC);
public:
	CLand();
	~CLand();
};

