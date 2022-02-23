#include "pch.h"
#include "CTimeManager.h"

CTimeManager::CTimeManager()
{
	m_uiFPS = 0;
	m_dDT = 0;
	m_llPrevCount;
	m_llCurCount;
	m_llFrequency;
}
CTimeManager::~CTimeManager()
{
}

void CTimeManager::update()
{
	//static unsigned int updateCount = 0;
	//static double updateOneSecond = 0;
	QueryPerformanceCounter(&m_llCurCount);
	//���� ������Ʈ ī��Ʈ�� ���� ������Ʈ ī��Ʈ ���� ���̸� ���ؼ�
	//1�ʴ� ī��Ʈ ���� �����ָ�, ������Ʈ ������ �� �ʰ� �������� �� �� �ִ�.
	m_dDT= (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;//���������Ʈ-����������Ʈī��Ʈ
	m_llPrevCount = m_llCurCount;

	

}

void CTimeManager::render()
{
	++m_iCallCount;
	m_dAcc += m_dDT;
	if (m_dAcc >= 1.f)//1�� ������ 1��
	{
		m_uiFPS = m_iCallCount;//==fps
		m_dAcc = 0;//�ٽ� �ʱ�ȭ
		m_iCallCount = 0;//�ٽ� �ʱ�ȭ

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS: %d, DT: %lf", m_uiFPS, m_dDT);
		SetWindowText(hWnd, szBuffer);
	}
}

void CTimeManager::init()
{
	QueryPerformanceCounter(&m_llPrevCount);	//���� �ð��� ī��Ʈ ��
	QueryPerformanceFrequency(&m_llFrequency);	//1�ʴ� �����ϴ� ī��Ʈ ��
}
