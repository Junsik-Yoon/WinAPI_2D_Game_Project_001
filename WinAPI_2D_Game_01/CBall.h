#pragma once
#include "CObject.h"

class CBall : public CObject
{
public:
	CBall();
	~CBall();
	int rando()
	{
		srand(time(NULL));
		return (rand() % 4);
	}
private:

public:
	void update();
	void render(HDC hDC);
};
