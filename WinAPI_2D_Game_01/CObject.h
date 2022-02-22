#pragma once
class CObject
{
private:
	fPoint m_vPos;
	fPoint m_vScale;

public:
	void SetPos(fPoint _vPos) { m_vPos = _vPos; };
	void SetScale(fPoint _vScale) { m_vScale = _vScale; };
	fPoint GetPos() { return m_vPos; }
	fPoint GetScale() { return m_vScale; }

public:
	virtual void update() = 0;
	virtual void render(HDC _dc)=0;
public:
	CObject();
	virtual ~CObject();
};

