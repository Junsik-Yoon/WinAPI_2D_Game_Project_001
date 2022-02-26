#include "pch.h"
#include "CKeyManager.h"

CKeyManager::CKeyManager()
{
	for (int key = 0; key < VKEY_SIZE; ++key)
	{
		m_arrPrevKey[key] = false;
		m_arrCurKey[key] = false;
	}
}
CKeyManager::~CKeyManager()
{

}

void CKeyManager::update()
{
	HWND curWnd = GetFocus();
	if (hWnd != curWnd)
	{
		for (int key = 0; key < VKEY_SIZE; ++key)
		{
			m_arrPrevKey[key] = m_arrCurKey[key];
			m_arrCurKey[key] = false;
		}
	}

	for (int key = 0; key < VKEY_SIZE; ++key)
	{
		m_arrPrevKey[key] = m_arrCurKey[key];
		if (GetAsyncKeyState(key) & 0x8000)
		{
			m_arrCurKey[key] = true;
		}
		else
		{
			m_arrCurKey[key] = false;
		}
	}
}

void CKeyManager::init()
{
}

bool CKeyManager::GetButton(const int key)
{
	return (true == m_arrPrevKey[key] && true == m_arrCurKey[key]);
}

bool CKeyManager::GetButtonDown(const int key)
{
	return (false == m_arrPrevKey[key] && true == m_arrCurKey[key]);
}

bool CKeyManager::GetButtonUP(const int key)
{
	return (true == m_arrPrevKey[key] && false == m_arrCurKey[key]);
}
