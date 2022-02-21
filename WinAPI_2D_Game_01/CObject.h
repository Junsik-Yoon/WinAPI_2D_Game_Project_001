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
	virtual void update()=0;//각자 자기가 구현해야지 update가 공통되는건 말이 안되므로 순수가상함수로 구현
	virtual void render(HDC _dc);
public:
	CObject();
	virtual ~CObject();
};



