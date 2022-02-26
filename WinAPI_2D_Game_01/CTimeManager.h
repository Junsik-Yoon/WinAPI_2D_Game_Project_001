#pragma once
class CTimeManager
{
	SINGLETON(CTimeManager);

private:
	LARGE_INTEGER m_llCurCount; //���� ī��Ʈ
	LARGE_INTEGER m_llPrevCount;//���� ī��Ʈ
	LARGE_INTEGER m_llFrequency;//�ʴ� ī��Ʈ Ƚ��
	unsigned int m_uiFPS;		//�ʴ� ������Ʈ Ƚ��
	double m_dDT;				//������Ʈ�� ������Ʈ ���� �ð�
public:
	void update(); //�� ������Ʈ�� fps , dt
	void init();   

	unsigned int	GetFPS(){ return m_uiFPS; }		//1�ʴ� ������
	double			GetDT() { return m_dDT; }		//1�����Ӵ� �ð�
	double			GetfDT() { return (float)m_dDT; }
};

