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

	// Mouse ��ǥ ���
	POINT ptPos = {};
	// GetCursorPos() �����쿡�� ����� �»�� ���� ���콺�� ��ǥ�� ��ȯ
	GetCursorPos(&ptPos);
	// ����� �»�� ���� ���콺 ��ǥ�� ���� ������ ���� ���콺 ��ġ�� ���
	ScreenToClient(hWnd, &ptPos);

	m_fptCurMousePos = Vec2((float)ptPos.x, (float)ptPos.y);
}

void CKeyManager::init()
{
}

