#pragma once
#include "CGameObject.h"
class CMissile :
    public CGameObject
{
private:
    float m_fVelocity;//�ӵ�
    fVec2 m_fDir;//����
    
public:
    virtual void update();
    virtual void render(HDC hdc);

    void SetDir(fVec2 _fDir) { m_fDir = _fDir; }

public:
    CMissile();
    ~CMissile();
};

