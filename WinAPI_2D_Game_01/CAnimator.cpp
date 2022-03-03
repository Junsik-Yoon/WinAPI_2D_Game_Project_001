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
		//이름이 똑같은 애니메이션을 넣었을 때 반응 -> 의도에따라다름
		//방법1.이미 있던걸 지우고 새로운 애니메이션 넣어주기
		//방법2. 이미 있으니까 무시
		//방법3. 있는데 넣는건 의도에 맞지 않으므로 assert로 죽이기
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


