#pragma once
class CGameObject
{
private:
	fVec2 m_fptPos; //물체의좌표
	fVec2 m_fptScale;//물체의크기

public:
	CGameObject();
	virtual ~CGameObject();

public:
	virtual void update()=0;//TODO: 순수가상함수처리
	virtual void render(HDC hDC)=0 ;

	void SetPos(fVec2 pos)		{ m_fptPos		= pos; }
	void SetScale(fVec2 scale) { m_fptScale	= scale; }
	fVec2 GetPos()				{ return m_fptPos; }
	fVec2 GetScale()			{ return m_fptScale; }
};

