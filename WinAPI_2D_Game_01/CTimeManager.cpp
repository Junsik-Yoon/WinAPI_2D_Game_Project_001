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
	//이전 업데이트 카운트와 현재 업데이트 카운트 값의 차이를 구해서
	//1초당 카운트 수로 나눠주면, 업데이트 사이의 몇 초가 지났는지 알 수 있다.
	m_dDT= (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;//현재업데이트-이젠업데이트카운트
	m_llPrevCount = m_llCurCount;

	

}

void CTimeManager::render()
{
	++m_iCallCount;
	m_dAcc += m_dDT;
	if (m_dAcc >= 1.f)//1이 넘으면 1초
	{
		m_uiFPS = m_iCallCount;//==fps
		m_dAcc = 0;//다시 초기화
		m_iCallCount = 0;//다시 초기화

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS: %d, DT: %lf", m_uiFPS, m_dDT);
		SetWindowText(hWnd, szBuffer);
	}
}

void CTimeManager::init()
{
	QueryPerformanceCounter(&m_llPrevCount);	//현재 시간의 카운트 수
	QueryPerformanceFrequency(&m_llFrequency);	//1초당 진행하는 카운트 수
}
