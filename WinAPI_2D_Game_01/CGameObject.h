#pragma once
class CGameObject
{
private:
	fPoint m_fptPos; //물체의좌표
	fPoint m_fptScale;//물체의크기

public:
	CGameObject();
	virtual ~CGameObject();

public:
	virtual void update()=0;//TODO: 순수가상함수처리
	virtual void render(HDC hDC)=0 ;

	void SetPos(fPoint pos)		{ m_fptPos		= pos; }
	void SetScale(fPoint scale) { m_fptScale	= scale; }
	fPoint GetPos()				{ return m_fptPos; }
	fPoint GetScale()			{ return m_fptScale; }
};

