#pragma once

class CAnimator;
class CTexture;

struct tAniFrm
{
	fVec2 fptLT;
	fVec2 fptSlice;
	fVec2 fptOffset;
	float fDuration;
};

class CAnimation
{
	friend class CAnimator;
	
private:
	wstring		m_strName;//�ִϸ��̼� �̸�
	CAnimator*	m_pAnimator;//�ִϸ����� ��������
	CTexture*	m_pTex;	//�ִϸ��̼� �̹���
	vector<tAniFrm> m_vecFrm; //��� �������� �ڸ��� ���� �� �����ð�
	int			m_iCurFrm; //���� ���° ���������� index
	float		m_fAccTime;	//���� �������� �����ð�

public:
	void SetName(const wstring& strName) { m_strName = strName; }
	const wstring& GetName() { return m_strName; }
	
	void SetFrame(int frmIndex) { m_iCurFrm = frmIndex; }
	tAniFrm& GetFrame(int frmIndex) { return m_vecFrm[frmIndex]; }

	void update();//���� ���ʰ� �׸����� �ľ��ؾ���
	void render(HDC hDC);

	void Create(CTexture* pTex, fVec2 lt, fVec2 slice, fVec2 step, float duration, UINT frmCount);//�ִϸ��̼� ����)
public:
	CAnimation();
	~CAnimation();

};

