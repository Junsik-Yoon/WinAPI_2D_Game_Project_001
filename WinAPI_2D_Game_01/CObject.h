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
	virtual void update()=0;//���� �ڱⰡ �����ؾ��� update�� ����Ǵ°� ���� �ȵǹǷ� ���������Լ��� ����
	virtual void render(HDC _dc);
public:
	CObject();
	virtual ~CObject();
};



