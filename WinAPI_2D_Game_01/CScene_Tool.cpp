#include "pch.h"
#include "CScene_Tool.h"
#include "CTile.h"
#include "CScene.h"
#include "resource.h"
#include "CTexture.h"
#include "commdlg.h"
#include "CUI.h"
#include "CButtonUI.h"
#include "CPanelUI.h"
#include "CCollider.h"
#include "CBG1.h"

INT_PTR CALLBACK TileWndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
CScene_Tool::CScene_Tool()
{
    m_hWnd = 0;
    m_iIdx = 0;
}

CScene_Tool::~CScene_Tool()
{

}

void CScene_Tool::update()
{
    CScene::update();

    if (KEYDOWN(VK_F1))
    {
        CEventManager::getInst()->EventChangeScene(GROUP_SCENE::START);
    }
    if (KEY('A'))
    {
        CCameraManager::getInst()->Scroll(Vec2(-1, 0), m_velocity);
    }
    if (KEY('D'))
    {
        CCameraManager::getInst()->Scroll(Vec2(1, 0), m_velocity);
    }
    if (KEY('W'))
    {
        CCameraManager::getInst()->Scroll(Vec2(0, -1), m_velocity);
    }
    if (KEY('S'))
    {
        CCameraManager::getInst()->Scroll(Vec2(0, 1), m_velocity);
    }

    SetTileIdx();
}

void buttonItemClicked(DWORD_PTR param1, DWORD_PTR param2)
{

}
void buttonMapClicked(DWORD_PTR param1, DWORD_PTR param2)
{

}

void CScene_Tool::Enter()
{
    CBG1* pBG = new CBG1();
    pBG->SetScale(Vec2(1.f, 1.f));
    pBG->SetPos(Vec2(0.f, 0.f));
    AddObject(pBG,GROUP_GAMEOBJ::BACKGROUND);

    CreateTile(5, 5);
    CCameraManager::getInst()->SetLookAt(Vec2(float(WINSIZEX / 2.f), float(WINSIZEY / 2.f)));
    m_hWnd = CreateDialog(hInst, MAKEINTRESOURCE(IDD_TILEBOX), hWnd, TileWndProc);
    ShowWindow(m_hWnd, SW_SHOW);

    ////UI����
    //CPanelUI* pUI = new CPanelUI();
    //pUI->SetScale(Vec2(200.f, 200.f));
    //pUI->SetCameraAffected(true);
    //pUI->SetPos(Vec2(WINSIZEX / 2.f, WINSIZEY / 2.f)); //UI�� ī�޶��� ��ġ�� ������� ������ǥ�� ���� �����ؾ��Ѵ�
    //AddObject(pUI, GROUP_GAMEOBJ::UI);
    //
    ////UI����
    //CPanelUI* pUI2 = new CPanelUI();
    //pUI2->SetScale(Vec2(200.f, 200.f));
    //pUI2->SetCameraAffected(true);
    //pUI2->SetPos(Vec2((WINSIZEX / 2.f)+200.f, WINSIZEY / 2.f)); //UI�� ī�޶��� ��ġ�� ������� ������ǥ�� ���� �����ؾ��Ѵ�
    //AddObject(pUI2, GROUP_GAMEOBJ::UI);

    //CUI* pChildUI = new CUI();
    //pChildUI->SetScale(Vec2(50.f, 50.f));
    //pChildUI->SetPos(Vec2(50.f, 50.f));
    //pUI->AddChild(pChildUI);

    //CButtonUI* pItemButton = new CButtonUI();
    //pItemButton->SetScale(Vec2(50.f, 50.f));
    //pItemButton->SetPos(Vec2(200.f, 150.f));
    //pItemButton->SetClickCallBack(buttonItemClicked, 0, 0);
    //pUI->AddChild(pItemButton);

    //CButtonUI* pMapButton = new CButtonUI();
    //pMapButton->SetScale(Vec2(50.f, 50.f));
    //pMapButton->SetPos(Vec2(100.f, 150.f));
    //pMapButton->SetClickCallBack(buttonItemClicked, 0, 0);
    //AddObject(pMapButton, GROUP_GAMEOBJ::UI);
   
}

void CScene_Tool::Exit()
{
    EndDialog(m_hWnd, IDOK);
    DeleteGroup(GROUP_GAMEOBJ::TILE);
}


void CScene_Tool::SetTileIdx()
{
    if (KEY(VK_LBUTTON))
    {
        Vec2 fptMousePos = MousePos();
        fptMousePos = CCameraManager::getInst()->GetRealPos(fptMousePos);
        
        int iTileX = (int)GetTileX();
        int iTileY = (int)GetTileY();

        int iCol = (int)fptMousePos.x / CTile::SIZE_TILE;
        int iRow = (int)fptMousePos.y / CTile::SIZE_TILE;

        if (fptMousePos.x < 0.f || iTileX <= iCol ||
            fptMousePos.y < 0.f || iTileY <= iRow)
        {
            return;     // Ÿ���� ���� ��ġ ����
        }

        UINT iIdx = iRow * iTileX + iCol;
        const vector<CGameObject*>& vecTile = GetGroupObject(GROUP_GAMEOBJ::TILE);
        ((CTile*)vecTile[iIdx])->SetTileIdx(m_iIdx);
        if (true == isColTile)
        {
            ((CTile*)vecTile[iIdx])->CreateCollider();
            ((CTile*)vecTile[iIdx])->GetCollider()->SetOffsetPos(Vec2(vecTile[iIdx]->GetScale().x / 2.f, vecTile[iIdx]->GetScale().y / 2.f));
            ((CTile*)vecTile[iIdx])->GetCollider()->SetScale(Vec2(vecTile[iIdx]->GetScale().x, vecTile[iIdx]->GetScale().y));
            ((CTile*)vecTile[iIdx])->SetCollider(true);

        }

    }
}

void CScene_Tool::SetIdx(UINT idx)
{
    m_iIdx = idx;
}




void CScene_Tool::SaveTile(const wstring& strPath)
{
    //wstring strFilePath = CPathManager::getInst()->GetContentPath();
    

    FILE* pFile = nullptr;

    _wfopen_s(&pFile, strPath.c_str(), L"wb");		// w : write, b : binary
    assert(pFile);

    UINT xCount = GetTileX();
    UINT yCount = GetTileY();

    fwrite(&xCount, sizeof(UINT), 1, pFile);
    fwrite(&yCount, sizeof(UINT), 1, pFile);

    const vector<CGameObject*>& vecTile = GetGroupObject(GROUP_GAMEOBJ::TILE);

    for (UINT i = 0; i < vecTile.size(); ++i)
    {
        ((CTile*)vecTile[i])->Save(pFile);
    }

    fclose(pFile);
}

void CScene_Tool::SaveTileData()
{
    OPENFILENAME ofn = {};

    ofn.lStructSize = sizeof(OPENFILENAME);  // ����ü ������.
    ofn.hwndOwner = hWnd;					// �θ� ������ ����.
    wchar_t szName[256] = {};
    ofn.lpstrFile = szName; // ���߿� �ϼ��� ��ΰ� ä���� ���� ����.
    ofn.nMaxFile = sizeof(szName); // lpstrFile�� ������ ������ ���� ��.
    ofn.lpstrFilter = L"ALL\0*.*\0tile\0*.tile"; // ���� ����
    ofn.nFilterIndex = 0; // �⺻ ���� ����. 0�� all�� �ʱ� ���õ�. ó����.
    ofn.lpstrFileTitle = nullptr; // Ÿ��Ʋ ��
    ofn.nMaxFileTitle = 0; // Ÿ��Ʋ �� ���ڿ� ũ��. nullptr�̸� 0.
    wstring strTileFolder = CPathManager::getInst()->GetContentPath();
    strTileFolder += L"tile";
    ofn.lpstrInitialDir = strTileFolder.c_str(); // �ʱ���. �츮�� Ÿ�� �����Ұű� ������, content->tile ��η� �ص���.
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST; // ��Ÿ��

    if (GetSaveFileName(&ofn))
    {
        SaveTile(szName);
    }
}

void CScene_Tool::LoadTileData()
{
    OPENFILENAME ofn = {};

    ofn.lStructSize = sizeof(OPENFILENAME);  // ����ü ������.
    ofn.hwndOwner = hWnd; // �θ� ������ ����.
    wchar_t szName[256] = {};
    ofn.lpstrFile = szName; // ���߿� �ϼ��� ��ΰ� ä���� ���� ����.
    ofn.nMaxFile = sizeof(szName); // lpstrFile�� ������ ������ ���� ��.
    ofn.lpstrFilter = L"ALL\0*.*\0tile\0*.tile"; // ���� ����
    ofn.nFilterIndex = 0; // �⺻ ���� ����. 0�� all�� �ʱ� ���õ�. ó����.
    ofn.lpstrFileTitle = nullptr; // Ÿ��Ʋ ��
    ofn.nMaxFileTitle = 0; // Ÿ��Ʋ �� ���ڿ� ũ��. nullptr�̸� 0.
    wstring strTileFolder = CPathManager::getInst()->GetContentPath();
    strTileFolder += L"tile";
    ofn.lpstrInitialDir = strTileFolder.c_str(); // �ʱ���. �츮�� Ÿ�� �����Ұű� ������, content->tile ��η� �ص���.
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST; // ��Ÿ��

    if (GetOpenFileName(&ofn))
    {
        LoadTile(szName);
    }
}

INT_PTR CALLBACK TileWndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK)
        {
            //TODO:�����ϱ�
            CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

            CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
            assert(pToolScene);

            pToolScene->SaveTileData();

            return (INT_PTR)TRUE;
        }
        else if (LOWORD(wParam) == IDCANCEL)
        {
            //TODO:�ҷ�����
            CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

            CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
            assert(pToolScene);

            pToolScene->LoadTileData();
            return (INT_PTR)TRUE;
        }
        else if (LOWORD(wParam) == IDC_BUTTON1)
        {
            //TODO:�Է��� ũ��δٰ� Ÿ�� ������ ����
            int x = GetDlgItemInt(hDlg, IDC_EDIT_SIZEX, nullptr, false);
            int y = GetDlgItemInt(hDlg, IDC_EDIT_SIZEY, nullptr, false);
            
            CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

            CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
            assert(pToolScene);

            pToolScene->DeleteGroup(GROUP_GAMEOBJ::TILE);
            pToolScene->CreateTile(x, y);
        }
        else if (LOWORD(wParam) == IDC_BUTTON2)
        {
            int m_iIdx = GetDlgItemInt(hDlg, IDC_EDIT_TILEIDX, nullptr, false);

            CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

            CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
            assert(pToolScene);

            CTexture* pTex = CResourceManager::getInst()->FindTexture(L"Tile");

            UINT iWidth = pTex->GetBmpWidth();
            UINT iHeight = pTex->GetBmpHeight();

            UINT iMaxRow = iHeight / CTile::SIZE_TILE;
            UINT iMaxCol = iWidth / CTile::SIZE_TILE;

            UINT iCurRow = (m_iIdx / iMaxCol) % iMaxRow;
            UINT iCurCol = (m_iIdx % iMaxCol);

            // �ӽ÷� �̹��� ���
            BitBlt(GetDC(hDlg),
                (int)(150),
                (int)(150),
                (int)(CTile::SIZE_TILE),
                (int)(CTile::SIZE_TILE),
                pTex->GetDC(),
                (int)(iCurCol * CTile::SIZE_TILE),
                (int)(iCurRow * CTile::SIZE_TILE),
                SRCCOPY);

            pToolScene->SetIdx(m_iIdx);
            ////�̸����� �׸���
            //CTexture* pTex = CResourceManager::getInst()->LoadTexture(L"Tile", L"texture\\Tile\\tilemap.bmp");

            //UINT iWidth = pTex->GetBmpWidth();
            //UINT iHeight = pTex->GetBmpHeight();
            //UINT iMaxRow = iHeight / CTile::SIZE_TILE;
            //UINT iMaxCol = iWidth / CTile::SIZE_TILE;

            //UINT iCurRow = (index / iMaxCol) % iMaxRow;
            //UINT iCurCol = (index % iMaxCol) ;
            //StretchBlt(GetDC(hDlg),
            //    150, 150, iCurCol * CTile::SIZE_TILE * 2
            //    iCurRow * CTile::SIZE_TILE * 2),
            //    CTile::SIZE_TILE, CTile::SIZE_TILE, SRCCOPY);

        }

        else if (LOWORD(wParam) == IDC_CHECKCOL)
        {
            HWND check = GetDlgItem(hDlg, IDC_CHECKCOL);
            if (SendMessage(check, BM_GETCHECK, 0, 0) == BST_UNCHECKED)
            {
                SetWindowText(hDlg, L"üũ����");
                CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

                CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
                assert(pToolScene);

                pToolScene->SetCollider(false);

            }
            else
            {
                SetWindowText(hDlg, L"üũ��");
                CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

                CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
                assert(pToolScene);

                pToolScene->SetCollider(true);
            }
            
        }

        break;
    }
    return (INT_PTR)FALSE;
}
