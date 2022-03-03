#include "pch.h"
#include "CAnimation.h"
#include "CAnimator.h"
#include "CGameObject.h"
#include "CTexture.h"

CAnimation::CAnimation()
{
	m_strName=L"";
	m_pAnimator = nullptr;
	m_pTex = nullptr;
	m_iCurFrm = 0;
	m_fAccTime = 0;
}

CAnimation::~CAnimation()
{
}

void CAnimation::update()
{
	//시간축적을 해서 fDuration>m_iCurFrm++
	m_fAccTime += fDT;
	if (m_fAccTime > m_vecFrm[m_iCurFrm].fDuration)
	{
		m_iCurFrm++;
		m_iCurFrm &= m_vecFrm.size();
		m_fAccTime = 0;
	}
}

void CAnimation::render(HDC hDC)
{
	CGameObject* pObj = m_pAnimator->GetObj();
	fVec2 fptPos = pObj->GetPos();
	tAniFrm frm = m_vecFrm[m_iCurFrm];

	fptPos = fptPos + frm.fptOffset;

	TransparentBlt(hDC,
		(int)(fptPos.x-frm.fptSlice.x/2.f),
		(int)(fptPos.y - frm.fptSlice.y / 2.f),
		(int)(frm.fptSlice.x),
		(int)(frm.fptSlice.y),
		m_pTex->GetDC(),
		(int)(frm.fptLT.y),
		(int)(frm.fptLT.x),
		(int)(frm.fptSlice.x),
		(int)(frm.fptSlice.y),
		 RGB(255, 0, 255));
}

void CAnimation::Create(CTexture* pTex, //애니메이션의 이미지
						fVec2 lt,		//애니메이션 시작프레임 좌상단좌표
						fVec2 slice,	//애니메이션 장면의 크기
						fVec2 step,		//애니메이션 프레임 반복위치
						float duration,//애니메이션 프레임 지속시간
						UINT frmCount)	//애니메이션 프레임 개수
{
	m_pTex = pTex;
	tAniFrm frm = {};
	for (UINT i = 0; i < frmCount; ++i)
	{
		frm.fDuration = duration;
		frm.fptSlice = slice;
		frm.fptLT = lt + step * i;
		m_vecFrm.push_back(frm);
	}

}
