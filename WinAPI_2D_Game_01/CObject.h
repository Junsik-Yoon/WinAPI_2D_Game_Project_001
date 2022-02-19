#pragma once
class CObject
{
private:
	fPoint m_vPos;
	fPoint m_ptScale;

public:
	void SetPos(fPoint _vPos) { m_vPos = _vPos; };
	void SetScale(fPoint _vScale) { m_ptScale = _vScale; };
	fPoint GetPos() { return m_vPos; }
	fPoint GetScale() { return m_ptScale; }
public:
	CObject();
	~CObject();
};



