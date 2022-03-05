#include "pch.h"
#include "CMidLine.h"
#include "CScene.h"
#include "CCollider.h"
#include "CMario.h"


CMidLine::CMidLine()
{
	SetPos(Vec2((float)WINSIZEX / 2.f, (float)WINSIZEY / 2.f));
	SetScale(Vec2(1.f, (float)WINSIZEY));
	CreateCollider();
	GetCollider()->SetScale(Vec2(GetScale().x, GetScale().y));
}

CMidLine::~CMidLine()
{
}

void CMidLine::update()
{
}

void CMidLine::render(HDC hDC)
{


	component_render(hDC);
}


