#include "pch.h"
#include "CBall.h"
#include "CRStick.h"
#include "CStick.h"
#include "CScene.h"
#include "CScene_Stage.h"

#define BLEFT vPos.x - GetScale().x/2
#define BRIGHT vPos.x + GetScale().x/2
#define BUP vPos.y - GetScale().y/2
#define BDOWN vPos.y + GetScale().y/2
enum class DIREC { RUP, RDOWN, LDOWN, LUP, STILL };
DIREC drc; //����
bool isFirstTime = true;


CBall::CBall()
{
}

CBall::~CBall()
{
}

void CBall::update()
{
	fPoint vPos=GetPos();


	//��
	//�� ���� ó�� ����
	if (true == isFirstTime)
	{
		switch (rando())//�� ���� ����
		{
		case 0: drc = DIREC::RDOWN;
			break;
		case 1: drc = DIREC::LDOWN;
			break;
		case 2: drc = DIREC::RUP;
			break;
		case 3: drc = DIREC::LUP;
			break;
		}
		isFirstTime = false;
	}
	//���� ���ʸ��뿡 ���� ��Ȳ
	else if ((vLPos.x - vLScale.x / 2 <= BLEFT) && (vLPos.x + vLScale.x / 2 >= BLEFT) && vPos.y > vLPos.y - vLScale.y / 2 && vPos.y < vLPos.y + vLScale.y / 2)
	{
		if (drc == DIREC::LDOWN)
			drc = DIREC::RDOWN;
		else if (drc == DIREC::LUP)
			drc = DIREC::RUP;
		if (vLScale.y > 20)//�پ�� �� �ִ� ������ 20���� ����
			vLScale.y -= 10;
		//�׽�Ʈ�غ��� ���̵��� ���� ������ �ȳ����� ���� ���뿡 ���������� ����� �ٵ��� ����߰�
	}
	//���� �����ʸ��뿡 ���� ��Ȳ
	else if ((vRPos.x + vRScale.x / 2 >= BRIGHT) && (vRPos.x - vRScale.x / 2 <= BRIGHT) && vPos.y > vRPos.y - vRScale.y / 2 && vPos.y < vRPos.y + vRScale.y / 2)
	{
		if (drc == DIREC::RDOWN)
			drc = DIREC::LDOWN;
		else if (drc == DIREC::RUP)
			drc = DIREC::LUP;
		if (vRScale.y > 20)
			vRScale.y -= 10;
	}
	//���� õ�忡 ���� ��Ȳ
	else if (vPos.y <= 0) //���� y���߽��� ��������������y��ǥ�� ���ٸ�(õ�忡����)
	{
		if (drc == DIREC::LUP)
			drc = DIREC::LDOWN;
		else if (drc == DIREC::RUP)
			drc = DIREC::RDOWN;

	}
	//���� �ٴڿ� ���� ��Ȳ
	else if (vPos.y >= WINSIZEY - GetScale().y / 2)//���� y���߽��� y�ػ󵵻������ ���������ݻ���� �� ���� ���ٸ�(�ٴڿ�����)
	{
		if (drc == DIREC::RDOWN)
			drc = DIREC::RUP;
		else if (drc == DIREC::LDOWN)
			drc = DIREC::LUP;
	}
	//���� ������ ����� ��Ȳ
	else if (vPos.x <= 0 - GetScale().x) //���� x���� ���ǻ����ŭ 0���� -�� �Ѿ�� ��
	{
		++rightPoint;
		vPos.x = WINSIZEX / 2;
		vPos.y = WINSIZEY / 2;
		switch (rando())//�� ���� ����
		{
		case 0: drc = DIREC::RDOWN;
			break;
		case 1: drc = DIREC::LDOWN;
			break;
		case 2: drc = DIREC::RUP;
			break;
		case 3: drc = DIREC::LUP;
			break;
		}
		if (5 == rightPoint)
		{
			MessageBoxW(hWnd, L"player2�� �¸��Ͽ����ϴ�", L"player2�¸�", MB_OK);
			drc = DIREC::STILL;
		}
	}
	//���� �������� ����� ��Ȳ
	else if (vPos.x >= WINSIZEX + GetScale().y)
	{
		++leftPoint;
		vPos.x = WINSIZEX / 2;
		vPos.y = WINSIZEY / 2;
		switch (rando())//�� ���� ����
		{
		case 0: drc = DIREC::RDOWN;
			break;
		case 1: drc = DIREC::LDOWN;
			break;
		case 2: drc = DIREC::RUP;
			break;
		case 3: drc = DIREC::LUP;
			break;
		}
		if (5 == leftPoint)
		{
			MessageBoxW(hWnd, L"player1�� �¸��Ͽ����ϴ�", L"player1�¸�", MB_OK);
			drc = DIREC::STILL;
		}
	}

	switch (drc)
	{
	case DIREC::RDOWN:
		vPos.x += BSPEED * DT;
		vPos.y += BSPEED * DT;
		break;
	case DIREC::RUP:
		vPos.x += BSPEED * DT;
		vPos.y -= BSPEED * DT;
		break;
	case DIREC::LDOWN:
		vPos.x -= BSPEED * DT;
		vPos.y += BSPEED * DT;
		break;
	case DIREC::LUP:
		vPos.x -= BSPEED * DT;
		vPos.y -= BSPEED * DT;
		break;
	default:
		break;
	}


	SetPos(vPos);
	
}

void CBall::render(HDC hDC)
{
	Ellipse(hDC, 
		GetPos().x - GetScale().x / 2,
		GetPos().y - GetScale().y / 2,
		GetPos().x + GetScale().x / 2,
		GetPos().y + GetScale().y / 2);
}
