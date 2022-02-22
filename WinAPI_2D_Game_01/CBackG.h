#pragma once
#include "CObject.h"
class CBackG : public CObject
{
public:
	CBackG();
	~CBackG();
private:

public:
	void update();
	void render(HDC hDC);


};

