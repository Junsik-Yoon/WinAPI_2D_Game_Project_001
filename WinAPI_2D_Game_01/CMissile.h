#pragma once
#include "CObject.h"
class CMissile :public CObject
{
private:
	float m_fDir; //�̻��� �� �Ʒ� ����
public:

	void SetDir(bool _bUp)
	{
		if (_bUp)
			m_fDir = -1.f;
		else
			m_fDir = 1.f;
	}

	virtual void update();
	virtual void render(HDC _dc);
public:
	CMissile();
	~CMissile();
};

