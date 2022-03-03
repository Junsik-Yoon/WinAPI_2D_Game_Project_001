#include "pch.h"
#include "CAnimator.h"
#include "CAnimation.h"


CAnimator::CAnimator()
{
	m_pOwner = nullptr;
	m_pCurAni = nullptr;
}

CAnimator::~CAnimator()
{
	for (map<wstring, CAnimation*>::iterator iter = m_mapAni.begin(); iter != m_mapAni.end(); ++iter)
	{
		if (nullptr != iter->second)
		{
			delete iter->second;
		}	
	}m_mapAni.clear();
}

void CAnimator::update()
{
	if (nullptr != m_pCurAni)
	{
		m_pCurAni->update();
	}
}

void CAnimator::render(HDC hDC)
{
	if (nullptr != m_pCurAni)
	{
		m_pCurAni->render(hDC);
	}
}

void CAnimator::CreateAnimation(const wstring& strName, CTexture* pTex, fVec2 lt, fVec2 slice, fVec2 step, float duration, UINT frmCount)
{
	CAnimation* pAni = FindAnimation(strName);
	if (nullptr != pAni)
	{
		//�̸��� �Ȱ��� �ִϸ��̼��� �־��� �� ���� -> �ǵ�������ٸ�
		//���1.�̹� �ִ��� ����� ���ο� �ִϸ��̼� �־��ֱ�
		//���2. �̹� �����ϱ� ����
		//���3. �ִµ� �ִ°� �ǵ��� ���� �����Ƿ� assert�� ���̱�
		assert(nullptr);
	}
	pAni = new CAnimation;
	pAni->SetName(strName);
	pAni->m_pAnimator = this;
	pAni->Create(pTex, lt, slice, step, duration, frmCount);

	m_mapAni.insert(std::make_pair(strName, pAni));
}

CAnimation* CAnimator::FindAnimation(const wstring& strName)
{
	map<wstring, CAnimation*>::iterator iter = m_mapAni.find(strName);
	if (iter == m_mapAni.end())
	{
		return nullptr;
	}
	return iter->second;
}

void CAnimator::Play(const wstring& strName)
{
	m_pCurAni = FindAnimation(strName);
}


