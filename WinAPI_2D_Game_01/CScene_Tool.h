#pragma once
#include "CScene.h"
class CScene_Tool :
    public CScene
{
private:
    HWND m_hWnd;
    UINT m_iIdx;
    float m_velocity = 300;
    bool isColTile = 0;
public:
    virtual void Enter();
    virtual void Exit();
    virtual void update();

    void SetCollider(bool val) { isColTile=val; }
    void SaveTile(const wstring& strPath);
    void SaveTileData();
    void LoadTileData();

public:
    void SetTileIdx(); //���콺�� ��ȣ�ۿ��ؼ� Ÿ���� �ٲ�
    void SetIdx(UINT idx);
public:
    CScene_Tool();
    ~CScene_Tool();
};

