#pragma once
#include "CUI.h"

//함수포인터를 위한 타입정의
typedef void(*BTN_FUNC)(DWORD_PTR, DWORD_PTR);

class CButtonUI :public CUI
{
private:
	BTN_FUNC m_pFunc;
	DWORD_PTR m_pParam1;
	DWORD_PTR m_pParam2;

public:

	virtual void MouseOn();
	virtual void MouseLbtnDown();
	virtual void MouseLbtnUp();
	virtual void MouseLbtnClicked();

	void SetClickCallBack(BTN_FUNC pFunc, DWORD_PTR param1, DWORD_PTR param2);

	

public:
	CButtonUI();
	~CButtonUI();
	//virtual CButtonUI Clone();
};

