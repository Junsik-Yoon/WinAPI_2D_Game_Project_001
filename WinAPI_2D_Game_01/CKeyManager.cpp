#include "pch.h"
#include "CKeyManager.h"

int g_arrVK[(int)KEY::LAST] =
{
	VK_UP,//UP,
	VK_DOWN,//DOWN,
	'W',//W,
	'S',//S,
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
	hWnd = GetFocus();

	if (nullptr != hWnd)
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
			{
				if (m_vecKey[i].bPrevPush)
					m_vecKey[i].eState = KEY_STATE::HOLD;
				else
					m_vecKey[i].eState = KEY_STATE::TAP;
				m_vecKey[i].bPrevPush = true;
			}
			else
			{
				if (m_vecKey[i].bPrevPush)

					m_vecKey[i].eState = KEY_STATE::AWAY;
				else
					m_vecKey[i].eState = KEY_STATE::NONE;
				m_vecKey[i].bPrevPush = false;
			}

		}
	}
	else
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			m_vecKey[i].bPrevPush = false;
			if (KEY_STATE::TAP == m_vecKey[i].eState || KEY_STATE::HOLD == m_vecKey[i].eState)
				m_vecKey[i].eState = KEY_STATE::AWAY;
			else if (KEY_STATE::AWAY == m_vecKey[i].eState)
				m_vecKey[i].eState = KEY_STATE::NONE;
		}

	}
}
