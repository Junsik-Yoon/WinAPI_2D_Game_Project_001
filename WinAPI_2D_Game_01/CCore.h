#pragma once
class CCore
{
	SINGLETON(CCore)

private:
	HWND m_hWnd; //���� ������ �ڵ�
	POINT m_ptResolution;//���� ������ �ػ�
	HDC m_hDC;
public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();
private:
	void update();
	void render();
};

