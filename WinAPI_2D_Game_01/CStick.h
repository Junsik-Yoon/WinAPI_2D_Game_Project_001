#pragma once
#include "CObject.h"
class CStick :public CObject
{
public:
	CStick();
	~CStick();
private:

public:
	void update();
	void render(HDC hDC);
};