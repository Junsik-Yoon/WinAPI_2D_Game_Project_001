#include "pch.h"
#include "CCore.h"

#include "CObject.h"

CObject g_obj;

CCore::CCore()
	:m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
	, m_hBit(0)
	,m_memDC(0)
{

}
CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);
	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
}
int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	CTimeManager::GetInst()->init();
	CKeyManager::GetInst()->init();
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;
	//�ػ󵵿� �°� ������ ũ�� ����	
	RECT rt = { 0,0,m_ptResolution.x,m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);

	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);

	g_obj.SetPos(fPoint((float)m_ptResolution.x/2,(float)m_ptResolution.y/2));
	g_obj.SetScale(fPoint(100,100));

	return S_OK;//init����üũ��
}


void CCore::progress()
{

	update();

	render();
}

void CCore::update()
{
	CTimeManager::GetInst()->update();
	CKeyManager::GetInst()->update();
	fPoint vPos = g_obj.GetPos();
	if (CKeyManager::GetInst()->GetKeyState(KEY::LEFT)==KEY_STATE::HOLD)//GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		vPos.x -= 200 *CTimeManager::GetInst()->getDT();
	}
	if (CKeyManager::GetInst()->GetKeyState(KEY::RIGHT) == KEY_STATE::HOLD)
	{
		vPos.x += (200 * CTimeManager::GetInst()->getDT());
	}
	if (CKeyManager::GetInst()->GetKeyState(KEY::UP) == KEY_STATE::HOLD)
	{
		vPos.y -= 200 * CTimeManager::GetInst()->getDT();
	}
	if (CKeyManager::GetInst()->GetKeyState(KEY::DOWN) == KEY_STATE::HOLD)
	{
		vPos.y += 200 * CTimeManager::GetInst()->getDT();
	}
	g_obj.SetPos(vPos);

}

void CCore::render()
{
	//ȭ�� clear
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);
	//�׸���
	fPoint vPos = g_obj.GetPos();
	fPoint vScale = g_obj.GetScale();
	Rectangle(m_memDC, vPos.x - vScale.x / 2.f,
					vPos.y - vScale.y / 2.f,
					vPos.x + vScale.x / 2.f,
					vPos.y + vScale.y / 2.f);
	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);
}




