#include "pch.h"
#include "CKeyManager.h"

CKeyManager::CKeyManager()
{
	//Ű ���¸� ��� ������ ���� ���·� �ʱ�ȭ
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
	//���缱��(Focus)�� �����찡 ���� �������ΰ��� Ȯ���ؼ�
	HWND curWnd = GetFocus();
	//���� ���� �����찡 ���õ� �����찡 �ƴ� ���
	if (hWnd != curWnd)
	{
		//�����찡 ���õ� ���°� �ƴ� ��� ��üŰ�Է��� ��� �ȴ������·� false ����ó����Ų��
		for (int key = 0; key < VKEY_SIZE; ++key)
		{
			m_arrPrevKey[key] = m_arrCurKey[key];
			m_arrCurKey[key] = false;
		}
	}

	//��� Ű �����ŭ �ݺ��ϸ鼭 �� Ű�� �Է»��¸� Ȯ��
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
	return (true == m_arrPrevKey[key] && true == m_arrCurKey[key]);//�������� ������ ���ݵ� ���ȴ�
}

bool CKeyManager::GetButtonDown(const int key)
{
	return (false == m_arrPrevKey[key] && true == m_arrCurKey[key]); //������ �ȴ����� ���� ���ȴ�
}

bool CKeyManager::GetButtonUP(const int key)
{
	return (true == m_arrPrevKey[key] && false == m_arrCurKey[key]);//������ ������ ������ �ȴ��ȴ�
}
