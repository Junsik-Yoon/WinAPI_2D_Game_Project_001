#pragma once
#include "CObject.h"
class CRStick : public CObject
{
public:
	CRStick();
	~CRStick();
private:

public:
	void update();
	void render(HDC hDC);
};