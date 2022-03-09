#pragma once
class CUI;

class CUIManager
{
	SINGLETON(CUIManager);
	//CUI* focusedUI;
private:

public:
	void update();

private:
	CUI* GetTargetUI(CUI* pParentUI);
	//CUI* GetFocusedUI();

};

