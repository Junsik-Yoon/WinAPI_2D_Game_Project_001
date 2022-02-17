#pragma once

#include "CSingleton.h"


class CCore
{
public:
	SINGLE(CCore);
private:
	CCore();
	~CCore();
public:
	void update();
	void render();
};

