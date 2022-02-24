#pragma once
#include "CGameObject.h"
class CMissile :
    public CGameObject
{
private:
    float m_fVelocity;//�ӵ�
    fVec2 m_fDir;//����
    float m_grav;//�߷�
    
public:
    virtual void update();
    virtual void render(HDC hdc);

    void SetDir(fVec2 _fDir) { m_fDir = _fDir; m_fDir.Normalize(); }
    //void SetDir(float theta) {}
public:
    CMissile();
    ~CMissile();
};

