#include "pch.h"
#include "CRStick.h"
#include "CScene.h"

CRStick::CRStick()
{
}

CRStick::~CRStick()
{
}

void CRStick::update()
{
	vRPos = GetPos();
	

	//player2 위아래
	if (KEY_HOLD(KEY::UP))//player2 위
	{
		if (vRPos.y > GetScale().y / 2)
		{
			vRPos.y -= SSPEED * DT;
		}
	}
	if (KEY_HOLD(KEY::DOWN))//player2 아래
	{
		if (vRPos.y < WINSIZEY - GetScale().y / 2)
		{
			vRPos.y += SSPEED * DT;
		}
	}

	SetPos(vRPos);
	SetScale(vRScale);
}

void CRStick::render(HDC hDC)
{
	Rectangle(hDC,
		GetPos().x - GetScale().x / 2,
		GetPos().y - GetScale().y / 2,
		GetPos().x + GetScale().x / 2,
		GetPos().y + GetScale().y / 2);
}
