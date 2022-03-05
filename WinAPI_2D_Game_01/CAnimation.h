
class CAnimator;
class CTexture;

struct tAniFrm
{
	Vec2 fptLT;
	Vec2 fptSlice;
	Vec2 fptOffset;
	float fDuration;
};

class CAnimation
{
	friend class CAnimator;

private:
	wstring			m_strName;		// �ִϸ��̼� �̸�
	CAnimator*		m_pAnimator;	// �ִϸ�����
	CTexture*		m_pTex;			// �ִϸ��̼� �̹���
	vector<tAniFrm> m_vecFrm;		// ��� �������� �ڸ��� ���� �� �����ð�
	int				m_iCurFrm;		// ���� �������� index
	float			m_fAccTime;		// ���� �����ӱ��� �����ð�

public:
	void update();
	void render(HDC hDC);

public:
	void SetName(const wstring& strName)	{ m_strName = strName; }
	const wstring& GetName()				{ return m_strName; }
	void SetFrame(int frmIndex)				{ m_iCurFrm = frmIndex; }
	tAniFrm& GetFrame(int frmIndex)			{ return m_vecFrm[frmIndex]; }

	void Create(CTexture* tex, Vec2 lt, Vec2 slice, Vec2 step, 
				float duration, UINT frmCount);

public:
	CAnimation();
	~CAnimation();
};