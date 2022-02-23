#pragma once
class CTimeManager
{
	SINGLETON(CTimeManager);

private:
	LARGE_INTEGER m_llCurCount; //현재 카운트 ll=longlong
	LARGE_INTEGER m_llPrevCount;//이전카운트
	LARGE_INTEGER m_llFrequency;//초당 카운트 횟수
	unsigned int m_uiFPS; //ui=unsigned //초당 업데이트 횟수
	double m_dDT;//업데이트와 업데이트 사이 시간
	UINT	m_iCallCount;//함수호출회수체크
	double m_dAcc;//1초 체크를 위한 누적 시간
public:
	void update(); //한 업데이트당 fps , dt
	void render();
	void init();   //

	unsigned int	GetFPS(){ return m_uiFPS; } //1초에 몇 프레임
	double			getDT() { return m_dDT; } //1프레임당 시간
	float			getfDT() { return(float)m_dDT; }
};

