#pragma once
#include "CScene.h"
class CScene_Info :
    public CScene
{
public:
    virtual void Enter() {}
    virtual void Exit(){}
public:
    CScene_Info();
    ~CScene_Info();
};

