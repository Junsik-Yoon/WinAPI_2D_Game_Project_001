#pragma once
#include "CGameObject.h"
class CMissile :
    public CGameObject
{
private:
    float m_fVelocity;//속도
    fVec2 m_fDir;//방향
    
public:
    virtual void update();
    virtual void render(HDC hdc);

    void SetDir(fVec2 _fDir) { m_fDir = _fDir; }

public:
    CMissile();
    ~CMissile();
};

