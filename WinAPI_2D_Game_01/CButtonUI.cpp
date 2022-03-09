#include "pch.h"
#include "CButtonUI.h"


CButtonUI::CButtonUI()
{
	m_pFunc = nullptr;
	//m_pParam1 = nullptr;
	//m_pParam2 = nullptr;
}

CButtonUI::~CButtonUI()
{
}



void CButtonUI::MouseOn()
{
	//���콺,�� �ö��� �� ��ư�� ���̶���Ʈ ǥ��
}

void CButtonUI::MouseLbtnDown()
{
	//����ǥ��
}

void CButtonUI::MouseLbtnUp()
{
	//����ǥ��
}

void CButtonUI::MouseLbtnClicked()
{
	if (nullptr != m_pFunc)
	{
		m_pFunc(m_pParam1, m_pParam2);
	}
}

void CButtonUI::SetClickCallBack(BTN_FUNC pFunc, DWORD_PTR param1, DWORD_PTR param2)
{
	m_pFunc = pFunc;
	m_pParam1 = param1;
	m_pParam2 = param2;
}
