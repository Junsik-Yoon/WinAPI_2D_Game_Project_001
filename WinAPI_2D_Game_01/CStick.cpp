#include "pch.h"
#include "CStick.h"
#include "CScene.h"

CStick::CStick()
{
}

CStick::~CStick()
{
}

void CStick::update()
{
	vLPos = GetPos();
	

	//Player1 ���Ʒ�
	if (KEY_HOLD(KEY::W))//Player1 ��
	{
		if (vLPos.y > GetScale().y / 2)
		{
			vLPos.y -= SSPEED * DT;
		}
	}
	if (KEY_HOLD(KEY::S))//Player1 �Ʒ�
	{
		if (vLPos.y < WINSIZEY - GetScale().y / 2)
		{
			vLPos.y += SSPEED * DT;
		}
	}


	SetPos(vLPos);
	SetScale(vLScale);

}

void CStick::render(HDC hDC)
{
	Rectangle(hDC, 
		GetPos().x - GetScale().x / 2,
		GetPos().y - GetScale().y / 2,
		GetPos().x + GetScale().x / 2,
		GetPos().y + GetScale().y / 2);
}
