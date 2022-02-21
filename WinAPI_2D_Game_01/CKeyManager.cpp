#include "pch.h"
#include "CKeyManager.h"

CKeyManager::CKeyManager()
{
	//키 상태를 모두 눌리지 않은 상태로 초기화
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
	//현재선택(Focus)된 윈도우가 게임 윈도우인가를 확인해서
	HWND curWnd = GetFocus();
	//만약 게임 윈도우가 선택된 윈도우가 아닐 경우
	if (hWnd != curWnd)
	{
		//윈도우가 선택된 상태가 아닐 경우 전체키입력을 모두 안눌린상태로 false 해제처리시킨다
		for (int key = 0; key < VKEY_SIZE; ++key)
		{
			m_arrPrevKey[key] = m_arrCurKey[key];
			m_arrCurKey[key] = false;
		}
	}

	//모든 키 사이즈만큼 반복하면서 그 키의 입력상태를 확인
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
	return (true == m_arrPrevKey[key] && true == m_arrCurKey[key]);//이전에도 눌리고 지금도 눌렸다
}

bool CKeyManager::GetButtonDown(const int key)
{
	return (false == m_arrPrevKey[key] && true == m_arrCurKey[key]); //이전에 안눌리고 지금 눌렸다
}

bool CKeyManager::GetButtonUP(const int key)
{
	return (true == m_arrPrevKey[key] && false == m_arrCurKey[key]);//이전에 눌리고 지금은 안눌렸다
}
