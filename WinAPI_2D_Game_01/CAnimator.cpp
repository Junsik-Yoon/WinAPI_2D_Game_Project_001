#include "pch.h"
#include "CAnimator.h"
#include "CAnimation.h"


CAnimator::CAnimator()
{
	m_pCurAni = nullptr;
	m_pOwner = nullptr;
}

CAnimator::~CAnimator()
{
	for (map<wstring, CAnimation*>::iterator iter = m_mapAni.begin(); iter != m_mapAni.end(); ++iter)
	{
		if (nullptr != iter->second)
			delete iter->second;
	}
	m_mapAni.clear();
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

void CAnimator::CreateAnimation(const wstring& strName, CTexture* tex, Vec2 lt, Vec2 slice, Vec2 step, float duration, UINT frmCount)
{
	CAnimation* pAni = FindAnimation(strName);
	assert(nullptr == pAni);

	pAni = new CAnimation;

	pAni->SetName(strName);
	pAni->m_pAnimator = this;
	pAni->Create(tex, lt, slice, step, duration, frmCount);

	m_mapAni.insert(make_pair(strName, pAni));
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

