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
	//마우스,가 올라갔을 때 버튼이 하이라이트 표시
}

void CButtonUI::MouseLbtnDown()
{
	//눌린표시
}

void CButtonUI::MouseLbtnUp()
{
	//원복표시
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
