#include "pch.h"
#include "CKeyManager.h"

int g_arrVK[(int)KEY::LAST] =
{
	VK_LEFT,//LEFT,
	VK_RIGHT,//RIGHT,
	VK_UP,//UP,
	VK_DOWN,//DOWN,
	'Q',//Q,
	'W',//W,
	'E',//E,
	'R',//R,
	'T',//T,
	'Y',//Y,
	'U',//U,
	'I',//I,
	'O',//O,
	'P',//P,
	'A',//A,
	'S',//S,
	'D',//D,
	'F',//F,
	'G',//G,
	'H',//H,
	'J',//J,
	'K',//K,
	'L',//L,
	'Z',//Z,
	'X',//X,
	'C',//C,
	'V',//V,
	'B',//B,
	'N',//N,
	'M',//M,
	VK_MENU,//ALT,
	VK_CONTROL,//CTRL,
	VK_LSHIFT,//LSHIFT,
	VK_SPACE,//SPACE,
	VK_RETURN,//ENTER,
	VK_ESCAPE,//ESC,

	//LAST,
};

CKeyManager::CKeyManager()
{

}
CKeyManager::~CKeyManager()
{

}
void CKeyManager::init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false });
	}
}

void CKeyManager::update()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		//키가 눌려있다.
		if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
		{
			if (m_vecKey[i].bPrevPush)
			{
				//이전에도 눌려있었다
				m_vecKey[i].eState = KEY_STATE::HOLD;
			}
			else
			{
				//이전에 눌려있지 않았다
				m_vecKey[i].eState = KEY_STATE::TAP;
			}
			m_vecKey[i].bPrevPush = true; //true로 토글해야 다음번 프레임계산에 눌려있는지 확인할 수 있음
		}
		//키가 안눌려있다
		else
		{
			if (m_vecKey[i].bPrevPush)
			{
				//이전에 눌려있었다.
				m_vecKey[i].eState = KEY_STATE::AWAY;
			}
			else
			{
				//이전에도 지금도 눌려있지 않았다
				m_vecKey[i].eState = KEY_STATE::NONE;
			}
			m_vecKey[i].bPrevPush = false;
		}
		
	}
}
