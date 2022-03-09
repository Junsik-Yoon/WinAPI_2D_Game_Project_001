#include "pch.h"
#include "CUIManager.h"
#include "CScene.h"
#include "CUI.h"


CUIManager::CUIManager()
{

}
CUIManager::~CUIManager()
{

}

void CUIManager::update()
{
	//TODO: ���콺�� �÷��� UI, ���� ,����, Ŭ����
	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	const vector<CGameObject*>& vecUI = pCurScene->GetGroupObject(GROUP_GAMEOBJ::UI);

	for (UINT i = 0; i < vecUI.size(); ++i)
	{
		CUI* pUI = (CUI*)vecUI[i];

		pUI = GetTargetUI(pUI);

		if (nullptr != pUI)//���콺�� �÷������� ��
		{
			pUI->IsMouseOn();
			if (KEYDOWN(VK_LBUTTON)) //���콺�� �÷��������鼭 ��ư�� ����
			{
				pUI->MouseLbtnDown();
				pUI->m_bLbtnDown = true;
			}
			else if (KEYUP(VK_LBUTTON))
			{
				pUI->MouseLbtnUp();
				if (pUI->m_bLbtnDown)
				{
					pUI->MouseLbtnClicked();
				}
				pUI->m_bLbtnDown = false;
			}
		}
	}

}

CUI* CUIManager::GetTargetUI(CUI* pParentUI)
{
	//�ڽ��� ���� ��ȸ
	//�ʺ�켱Ž�� queue��
	static list<CUI*> queue;
	static vector<CUI*> vecNoneTarget;
	CUI* pTargetUI = nullptr;

	queue.push_back(pParentUI);

	while (!queue.empty())
	{
		CUI* pUI = queue.front();
		queue.pop_front();

		if (pUI->IsMouseOn())
		{
			if (nullptr != pTargetUI)
			{
				vecNoneTarget.push_back(pTargetUI);
			}
			pTargetUI = pUI;
		}
		else
		{
			vecNoneTarget.push_back(pUI);
		}

		const vector<CUI*>& vecChild = pUI->GetChildUI();
		for (size_t i = 0; i < vecChild.size(); ++i)
		{
			queue.push_back(vecChild[i]);
		}

	}

	if (KEYUP(VK_LBUTTON))
	{
		for (size_t i = 0; i < vecNoneTarget.size(); i++)
		{
			vecNoneTarget[i]->m_bLbtnDown = false;
		}
	}
	
	return pTargetUI;
}
//
//CUI* CUIManager::GetFocusedUI()
//{
//	CScene* pCurScene = nullptr;
//	return nullptr;
//}
