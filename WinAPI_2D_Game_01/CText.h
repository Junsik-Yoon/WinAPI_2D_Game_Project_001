#pragma once
#include "CObject.h"
class CText :public CObject
{
public:
	CText() {};
	~CText() {};
	void update() {};
	void render(HDC hDC) 
	{
		WCHAR startMessage[20];
		swprintf_s(startMessage, L"시작하시려면 space를 눌러주세요");
		TextOutW(hDC, WINSIZEX / 2 - 140, WINSIZEY / 2, startMessage, 19);
	};
};

