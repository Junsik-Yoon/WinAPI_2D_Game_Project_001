#pragma once
#include "CScene.h"
class CScene_Info :
    public CScene
{
private:
    float fTimeCounter;
public:
    virtual void update();
    virtual void Enter();
    virtual void Exit();
public:
    CScene_Info();
    ~CScene_Info();
};

