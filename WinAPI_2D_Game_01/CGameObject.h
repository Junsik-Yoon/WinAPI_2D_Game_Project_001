#pragma once
class CGameObject
{
private:
	fPoint m_fptPos; //��ü����ǥ
	fPoint m_fptScale;//��ü��ũ��

public:
	CGameObject();
	~CGameObject();

public:
	virtual void update();//TODO: ���������Լ�ó��
	virtual void render(HDC hDC) ;

	void SetPos(fPoint pos)		{ m_fptPos		= pos; }
	void SetScale(fPoint scale) { m_fptScale	= scale; }
	fPoint GetPos()				{ return m_fptPos; }
	fPoint GetScale()			{ return m_fptScale; }
};

