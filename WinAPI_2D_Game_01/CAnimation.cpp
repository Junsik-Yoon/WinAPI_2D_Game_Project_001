#include "pch.h"
#include "CAnimation.h"
#include "CAnimator.h"
#include "CGameObject.h"
#include "CTexture.h"


CAnimation::CAnimation()
{
    m_strName = L"";
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
    m_fAccTime += fDT;

    if (m_vecFrm[m_iCurFrm].fDuration < m_fAccTime)
    {
        m_iCurFrm++;
        m_iCurFrm %= m_vecFrm.size();
        m_fAccTime -= m_vecFrm[m_iCurFrm].fDuration;
    }
}

void CAnimation::render(HDC hDC)
{
    CGameObject* pObj = m_pAnimator->GetObj();
    Vec2 fptPos = pObj->GetPos();
    tAniFrm frm = m_vecFrm[m_iCurFrm];

    fptPos = fptPos + frm.fptOffset;
    fptPos = CCameraManager::getInst()->GetRenderPos(fptPos);

    TransparentBlt(hDC,
        (int)(fptPos.x - frm.fptSlice.x / 2.f),
        (int)(fptPos.y - frm.fptSlice.y / 2.f),
        (int)(frm.fptSlice.x),
        (int)(frm.fptSlice.y),
        m_pTex->GetDC(),
        (int)(frm.fptLT.x),
        (int)(frm.fptLT.y),
        (int)(frm.fptSlice.x),
        (int)(frm.fptSlice.y),
        RGB(255, 0, 255));
}

void CAnimation::Create(CTexture* tex,      // �ִϸ��̼��� �̹���
                         Vec2 lt,           // �ִϸ��̼� ���� �������� �»�� ��ǥ
                         Vec2 slice,        // �ִϸ��̼� �������� ũ��
                         Vec2 step,         // �ִϸ��̼� �������� �ݺ� ��ġ
                         float duration,    // �ִϸ��̼� ������ ���ӽð�
                         UINT frmCount)     // �ִϸ��̼� ������ ����
{
    m_pTex = tex;

    tAniFrm frm = {};
    for (UINT i = 0; i < frmCount; i++)
    {
        frm.fDuration = duration;
        frm.fptSlice = slice;
        frm.fptLT = lt + step * i;

        m_vecFrm.push_back(frm);
    }
}


