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
    CreateTile(5, 5);
    CCameraManager::getInst()->SetLookAt(Vec2(float(WINSIZEX / 2.f), float(WINSIZEY / 2.f)));
    m_hWnd = CreateDialog(hInst, MAKEINTRESOURCE(IDD_TILEBOX), hWnd, TileWndProc);
    ShowWindow(m_hWnd, SW_SHOW);

    //UI생성
    CPanelUI* pUI = new CPanelUI();
    pUI->SetScale(Vec2(200.f, 200.f));
    pUI->SetCameraAffected(true);
    pUI->SetPos(Vec2(WINSIZEX / 2.f, WINSIZEY / 2.f)); //UI는 카메라의 위치와 상관없이 절대좌표를 통해 구현해야한다
    AddObject(pUI, GROUP_GAMEOBJ::UI);
    
    //UI복사
    CPanelUI* pUI2 = new CPanelUI();
    pUI2->SetScale(Vec2(200.f, 200.f));
    pUI2->SetCameraAffected(true);
    pUI2->SetPos(Vec2((WINSIZEX / 2.f)+200.f, WINSIZEY / 2.f)); //UI는 카메라의 위치와 상관없이 절대좌표를 통해 구현해야한다
    AddObject(pUI2, GROUP_GAMEOBJ::UI);

    CUI* pChildUI = new CUI();
    pChildUI->SetScale(Vec2(50.f, 50.f));
    pChildUI->SetPos(Vec2(50.f, 50.f));
    pUI->AddChild(pChildUI);

    CButtonUI* pItemButton = new CButtonUI();
    pItemButton->SetScale(Vec2(50.f, 50.f));
    pItemButton->SetPos(Vec2(150.f, 150.f));
    pItemButton->SetClickCallBack(buttonItemClicked, 0, 0);
    pUI->AddChild(pItemButton);

    CButtonUI* pMapButton = new CButtonUI();
    pMapButton->SetScale(Vec2(50.f, 50.f));
    pMapButton->SetPos(Vec2(150.f, 150.f));
    pMapButton->SetClickCallBack(buttonItemClicked, 0, 0);
    AddObject(pMapButton, GROUP_GAMEOBJ::UI);
   
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
            return;     // 타일이 없는 위치 무시
        }

        UINT iIdx = iRow * iTileX + iCol;
        const vector<CGameObject*>& vecTile = GetGroupObject(GROUP_GAMEOBJ::TILE);
        ((CTile*)vecTile[iIdx])->SetTileIdx(m_iIdx);


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

    ofn.lStructSize = sizeof(OPENFILENAME);  // 구조체 사이즈.
    ofn.hwndOwner = hWnd;					// 부모 윈도우 지정.
    wchar_t szName[256] = {};
    ofn.lpstrFile = szName; // 나중에 완성된 경로가 채워질 버퍼 지정.
    ofn.nMaxFile = sizeof(szName); // lpstrFile에 지정된 버퍼의 문자 수.
    ofn.lpstrFilter = L"ALL\0*.*\0tile\0*.tile"; // 필터 설정
    ofn.nFilterIndex = 0; // 기본 필터 세팅. 0는 all로 초기 세팅됨. 처음꺼.
    ofn.lpstrFileTitle = nullptr; // 타이틀 바
    ofn.nMaxFileTitle = 0; // 타이틀 바 문자열 크기. nullptr이면 0.
    wstring strTileFolder = CPathManager::getInst()->GetContentPath();
    strTileFolder += L"tile";
    ofn.lpstrInitialDir = strTileFolder.c_str(); // 초기경로. 우리는 타일 저장할거기 때문에, content->tile 경로로 해두자.
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST; // 스타일

    if (GetSaveFileName(&ofn))
    {
        SaveTile(szName);
    }
}

void CScene_Tool::LoadTileData()
{
    OPENFILENAME ofn = {};

    ofn.lStructSize = sizeof(OPENFILENAME);  // 구조체 사이즈.
    ofn.hwndOwner = hWnd; // 부모 윈도우 지정.
    wchar_t szName[256] = {};
    ofn.lpstrFile = szName; // 나중에 완성된 경로가 채워질 버퍼 지정.
    ofn.nMaxFile = sizeof(szName); // lpstrFile에 지정된 버퍼의 문자 수.
    ofn.lpstrFilter = L"ALL\0*.*\0tile\0*.tile"; // 필터 설정
    ofn.nFilterIndex = 0; // 기본 필터 세팅. 0는 all로 초기 세팅됨. 처음꺼.
    ofn.lpstrFileTitle = nullptr; // 타이틀 바
    ofn.nMaxFileTitle = 0; // 타이틀 바 문자열 크기. nullptr이면 0.
    wstring strTileFolder = CPathManager::getInst()->GetContentPath();
    strTileFolder += L"tile";
    ofn.lpstrInitialDir = strTileFolder.c_str(); // 초기경로. 우리는 타일 저장할거기 때문에, content->tile 경로로 해두자.
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST; // 스타일

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
            //TODO:저장하기
            CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

            CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
            assert(pToolScene);

            pToolScene->SaveTileData();

            return (INT_PTR)TRUE;
        }
        else if (LOWORD(wParam) == IDCANCEL)
        {
            //TODO:불러오기
            CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

            CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
            assert(pToolScene);

            pToolScene->LoadTileData();
            return (INT_PTR)TRUE;
        }
        else if (LOWORD(wParam) == IDC_BUTTON1)
        {
            //TODO:입력한 크기로다가 타일 개수를 세팅
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

            // 임시로 이미지 출력
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
            ////미리보기 그리기
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
        break;
    }
    return (INT_PTR)FALSE;
}
