#pragma once
#include "CObject.h"
class CMissile :public CObject
{
private:
	float m_fTheta; //이동방향
public:

	void SetDir(float _fTheta){m_fTheta = _fTheta;}

	virtual void update();
	virtual void render(HDC _dc);
public:
	CMissile();
	~CMissile();
};

