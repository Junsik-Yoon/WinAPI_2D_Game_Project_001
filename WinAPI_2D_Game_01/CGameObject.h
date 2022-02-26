#pragma once
class CGameObject
{
private:
	fPoint m_fptPos;	//ÁÂÇ¥
	fPoint m_fptScale;	//Å©±â

public:
	CGameObject();
	virtual ~CGameObject();

public:
	virtual void update()		=0;
	virtual void render(HDC hDC)=0;

	void SetPos(fPoint pos)		{ m_fptPos		= pos; }
	void SetScale(fPoint scale) { m_fptScale	= scale; }
	fPoint GetPos()				{ return m_fptPos; }
	fPoint GetScale()			{ return m_fptScale; }
};

