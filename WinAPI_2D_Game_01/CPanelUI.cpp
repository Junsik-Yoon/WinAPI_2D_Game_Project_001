#include "pch.h"
#include "CPanelUI.h"

CPanelUI::CPanelUI()
{
	m_fptDragStart = {};
}

CPanelUI::CPanelUI(const CPanelUI& other)
{
	CUI::CUI(other);
	m_fptDragStart = other.m_fptDragStart;
}

CPanelUI::~CPanelUI()
{
}


void CPanelUI::MouseOn()
{
	if (IsLbtnDown())
	{
		Vec2 fptDiff = MousePos() - m_fptDragStart; // �̵���ŭ�� ����

		Vec2 fptCurPos = GetPos();
		fptCurPos += fptDiff;
		SetPos(fptCurPos);

		m_fptDragStart = MousePos();//�ٽ� �ʱ�ȭ
	}
}

void CPanelUI::MouseLbtnDown()
{
}

void CPanelUI::MouseLbtnUp()
{
}

void CPanelUI::MouseLbtnClicked()
{
}

