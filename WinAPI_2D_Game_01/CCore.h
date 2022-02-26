#pragma once

class CCore
{
public:
	SINGLETON(CCore);
public:
	void init();
	void update();
	void render();

	HDC GetMainDC() { return m_hMemDC; }

private:
	HDC		m_hDC;		//������DC
	HDC		m_hMemDC;	//�޸�DC
	HBITMAP	m_hBMP;		//�޸𸮺�Ʈ��
};

