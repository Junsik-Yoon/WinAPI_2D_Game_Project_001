#pragma once
class CObject
{
private:
	fPoint m_vPos;
	fPoint m_ptScale;

public:
	void setPos(fPoint _vPos) { m_vPos = _vPos; };
	void setScale(fPoint _vScale) { m_ptScale = _vScale; };
	fPoint getPos() { return m_vPos; }
	fPoint getScale() { return m_ptScale; }
public:
	CObject();
	~CObject();
};

