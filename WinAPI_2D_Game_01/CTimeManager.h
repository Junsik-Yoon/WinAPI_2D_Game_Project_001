#pragma once
class CTimeManager
{
	SINGLETON(CTimeManager);

private:
	LARGE_INTEGER m_llCurCount; //���� ī��Ʈ ll=longlong
	LARGE_INTEGER m_llPrevCount;//����ī��Ʈ
	LARGE_INTEGER m_llFrequency;//�ʴ� ī��Ʈ Ƚ��
	unsigned int m_uiFPS; //ui=unsigned //�ʴ� ������Ʈ Ƚ��
	double m_dDT;//������Ʈ�� ������Ʈ ���� �ð�
public:
	void update(); //�� ������Ʈ�� fps , dt
	void init();   //

	unsigned int	GetFPS(){ return m_uiFPS; } //1�ʿ� �� ������
	double			getDT() { return m_dDT; } //1�����Ӵ� �ð�
	float			getfDT() { return(float)m_dDT; }
};

