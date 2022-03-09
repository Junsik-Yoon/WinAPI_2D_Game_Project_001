#pragma once
#include "CUI.h"


class CPanelUI : public CUI
{
private:
	Vec2 m_fptDragStart;
	Vec2 fptCurPos;
public:
	virtual void MouseOn();
	virtual void MouseLbtnDown();
	virtual void MouseLbtnUp();
	virtual void MouseLbtnClicked();

public:
	CPanelUI();
	CPanelUI(const CPanelUI& other);
	~CPanelUI();

	virtual CPanelUI* Clone(){return new CPanelUI(*this);}
};

