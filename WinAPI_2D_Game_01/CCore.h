#pragma once

class CCore
{
public:
	SINGLETON(CCore);
public:
	void init();
	void update();
	void render();

private:
	HDC		m_hDC;		//������DC
	HDC		m_hMemDC;	//�޸�DC
	HBITMAP	m_hBMP;		//�޸𸮺�Ʈ��
};

