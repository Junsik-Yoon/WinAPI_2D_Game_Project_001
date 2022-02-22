#include "pch.h"
#include "CBackG.h"

CBackG::CBackG()
{
}

CBackG::~CBackG()
{
}

void CBackG::update()
{
}

void CBackG::render(HDC hDC)
{
	//게임스코어
	for (int i = 0; i < 5; ++i)
	{
		if (i + 1 <= leftPoint)
			Rectangle(hDC, 30 + i * 5, 30, 32 + i * 5, 60);
	}
	for (int i = 0; i < 5; ++i)
	{
		if (i + 1 <= rightPoint)
			Rectangle(hDC, 1100 + i * 5, 30, 1102 + i * 5, 60);
	}
	//중심선
	Rectangle(hDC, (WINSIZEX / 2) - 1, 0, (WINSIZEX / 2) + 1, WINSIZEY);

}
