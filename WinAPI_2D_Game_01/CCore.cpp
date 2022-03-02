#include "pch.h"
#include "CCore.h"
#include "CGameObject.h"
#include "CScene.h"

CCore::CCore()
{
}
CCore::~CCore()
{
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);
	for (int i = 0; i < (UINT)TYPE_PEN::SIZE; ++i)
	{
		DeleteObject(m_arrPen[i]);
	}
}

void CCore::update()
{
	
	CTimeManager::getInst()->update();
	CKeyManager::getInst()->update();
	CSceneManager::getInst()->update();
	CCollisionManager::getInst()->update();
	//������ ������ ����
	
//	if (KEYDOWN(VK_SPACE)) //����ȯ����
	//	sceneChange = true; //��Ÿ��

}

void CCore::render()
{
	//������ ������ ���� �׷��ִ� �۾�
	Rectangle(m_hMemDC, -1 ,- 1, WINSIZEX + 1, WINSIZEY + 1);


	CSceneManager::getInst()->render(m_hMemDC);


	//fps�� ǥ��
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);
	//SetWindowTextW(hWnd, strFPS);
	
	//memDC �׸� ���纻�� ���� DC�� �׸��� �۾�
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
}
void CCore::CreateBrushPen()
{
	//brush
	m_arrBrush[(UINT)TYPE_BRUSH::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	
	//pen
	m_arrPen[(UINT)TYPE_PEN::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)TYPE_PEN::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)TYPE_PEN::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

	
}
HPEN CCore::GetPen(TYPE_PEN type)
{
	return m_arrPen[(UINT)type];
}
HBRUSH CCore::GetBrush(TYPE_BRUSH type)
{
	return m_arrBrush[(UINT)type];
}
void CCore::init()
{
	//Core�� �ʱ�ȭ
	CPathManager::getInst()->init();
	CTimeManager::getInst()->init();
	CKeyManager::getInst()->init();
	CSceneManager::getInst()->init();
	CCollisionManager::getInst()->init();

	CreateBrushPen();

	m_hDC = GetDC(hWnd);
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	//CGameObject* obj1 = new CGameObject;

	
}




