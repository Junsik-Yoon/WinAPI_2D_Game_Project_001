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
	static unsigned int updateCount = 0;
	static double updateOneSecond = 0;
	QueryPerformanceCounter(&m_llCurCount);
	//이전 업데이트 카운트와 현재 업데이트 카운트 값의 차이를 구해서
	//1초당 카운트 수로 나눠주면, 업데이트 사이의 몇 초가 지났는지 알 수 있다.
	m_dDT= (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / m_llFrequency.QuadPart;//현재업데이트-이젠업데이트카운트
	m_llPrevCount = m_llCurCount;

	//1초에 몇 번 업데이트가 되었는지
	++updateCount;
	updateOneSecond += m_dDT;
	if (updateOneSecond >= 1.f)
	{
		m_uiFPS = updateCount;
		updateOneSecond = 0;
		updateCount = 0;
	}
}

void CTimeManager::init()
{
	QueryPerformanceCounter(&m_llPrevCount);	//현재 시간의 카운트 수
	QueryPerformanceFrequency(&m_llFrequency);	//1초당 진행하는 카운트 수
}
