#pragma once

class CGameObject;
class CAnimation;

class CAnimator
{
	friend class CGameObject;
private:
	map<wstring, CAnimation*> m_mapAni;
	CAnimation* m_pCurAni;//현재애니메이션
	CGameObject* m_pOwner;

public:
	void CreateAnimation(const wstring& strName, CTexture* pTex, fVec2 lt, fVec2 slice, fVec2 step, float duration, UINT frmCount);
	CAnimation* FindAnimation(const wstring& strName);
	void Play(const wstring& strName);

	CGameObject* GetObj() { return m_pOwner; }

	void update();
	void render(HDC hDC);

public:
	CAnimator();
	~CAnimator();

};

