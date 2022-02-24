#include "pch.h"
#include "CLand.h"

CLand::CLand()
{
	SetPos(fVec2(WINSIZEX / 2, -1));
	SetScale(fVec2(WINSIZEX, 30));
}

CLand::~CLand()
{
}


void CLand::update()
{
	
}

void CLand::render(HDC hDC)
{
	Rectangle(hDC, GetPos().x - GetScale().x,
		GetPos().y - GetScale().y,
		GetPos().x + GetScale().x,
		GetPos().y + GetScale().y);
}