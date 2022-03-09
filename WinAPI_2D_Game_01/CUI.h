#pragma once
#include "CGameObject.h"
class CUI : public CGameObject
{
	friend class CUIManager;
private:
	vector<CUI*> m_vecChildUI;
	CUI* m_pParentUI;

	Vec2 m_fptFinalPos; //������� �ڽ��� �׷��� ��ġ(���Ӿ��̳� �θ�ui�ȿ� ���� ��)


	bool m_bCameraAffected; //ī�޶� ��ġ�� ui�� ������ �޴°������� ����
	bool m_bMouseOn;	//UI�� ���� �����ӿ� ���콺�� �÷��� �־���.
	bool m_bLbtnDown;	//UI�� ���� �����ӿ� ���Ⱦ���.

public:
	virtual void update();
	virtual void render(HDC hDC);
	virtual void finalupdate();


	void update_child();
	void finalupdate_child();
	void render_child(HDC hDC);

	virtual void MouseOn();
	virtual void MouseLbtnDown();//Ŭ�������δ� ���ڸ����� Ŭ���ϰ� Ŭ�������ϴ°͹ۿ� �����Ҽ�����
	virtual void MouseLbtnUp();//�ƴϸ� ����ó������ ��ư ����Ʈ�� �ٲ�ٴ��� �� �� �����
	virtual void MouseLbtnClicked();


public:
	Vec2 GetFinalPos() { return m_fptFinalPos; }
	CUI* GetParent() { return m_pParentUI; }
	const vector<CUI*>& GetChildUI();//����ڽĹ�ȯ

	void SetCameraAffected(bool affected) 
	{
		m_bCameraAffected = affected;
		for (int i = 0; i < m_vecChildUI.size(); ++i) 
		{ m_vecChildUI[i]->m_bCameraAffected = affected; }
	}
	bool GetCameraAffected() { return m_bCameraAffected; }
	bool IsMouseOn() { return m_bMouseOn; }
	bool IsLbtnDown() { return m_bLbtnDown; }


	void AddChild(CUI* pUI);
private:
	void MouseOnCheck();

public:
	CUI();
	CUI(const CUI& other);
	virtual ~CUI();
	virtual CUI* Clone() 
	{ 
		CUI* newUI = new CUI(*this); 
		newUI->m_vecChildUI.clear();
		for (UINT i = 0; i < m_vecChildUI.size(); ++i)
		{
			newUI->m_vecChildUI.push_back(new CUI(*m_vecChildUI[i]));
			newUI->m_vecChildUI[i]->m_pParentUI = newUI;//�θ���
		}
		return newUI;
	}
};

