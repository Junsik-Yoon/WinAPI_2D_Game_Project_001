#pragma once
#include "CGameObject.h"

class CTexture;

class CLou :
    public CGameObject
{

private:
    CTexture* m_pTex;
public:
    virtual void OnCollisionEnter(CCollider* _pOther);
    virtual void OnCollision(CCollider* _pOther);
    virtual void OnCollisionExit(CCollider* _pOther);
public:
    virtual void update();
    virtual void render(HDC hDC);

public:
    CLou();
    ~CLou();
    CLou* Clone() { return new CLou(*this); }
};

