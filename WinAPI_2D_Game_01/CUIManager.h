#pragma once
class CUI;

class CUIManager
{
	SINGLETON(CUIManager);
	CUI* m_pFocusedUI;
private:

public:
	void update();
	void SetFocusedUI(CUI* pUI);//Ŭ�� �̿ܿ��� â�� ��Ŀ���� ���� �� �ֵ���

private:
	CUI* GetTargetUI(CUI* pParentUI);
	CUI* GetFocusedUI();

};

