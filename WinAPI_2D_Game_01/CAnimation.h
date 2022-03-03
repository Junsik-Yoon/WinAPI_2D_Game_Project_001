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
	wstring		m_strName;//애니메이션 이름
	CAnimator*	m_pAnimator;//애니메이터 서로참조
	CTexture*	m_pTex;	//애니메이션 이미지
	vector<tAniFrm> m_vecFrm; //모든 프레임의 자르기 영역 및 유지시간
	int			m_iCurFrm; //현재 몇번째 프레임인지 index
	float		m_fAccTime;	//현재 프레임의 축적시간

public:
	void SetName(const wstring& strName) { m_strName = strName; }
	const wstring& GetName() { return m_strName; }
	
	void SetFrame(int frmIndex) { m_iCurFrm = frmIndex; }
	tAniFrm& GetFrame(int frmIndex) { return m_vecFrm[frmIndex]; }

	void update();//컷을 몇초간 그리는지 파악해야함
	void render(HDC hDC);

	void Create(CTexture* pTex, fVec2 lt, fVec2 slice, fVec2 step, float duration, UINT frmCount);//애니메이션 생성)
public:
	CAnimation();
	~CAnimation();

};

