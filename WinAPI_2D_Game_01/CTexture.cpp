#include "pch.h"
#include "CTexture.h"


CTexture::CTexture()
{
	m_hDC = 0;
	m_hBMP = 0;
	m_bmpInfo = {};
}

CTexture::~CTexture()
{
	DeleteDC(m_hDC);
	DeleteObject(m_hBMP);
}

void CTexture::Load(const wstring& strFilePath)
{
	m_hBMP = (HBITMAP)LoadImage(
		nullptr,				
		strFilePath.c_str(),						//������ ���
		IMAGE_BITMAP,								//�̹��� Ÿ��
		0, 0,										//�̹����� xyũ��, 0==default
		LR_CREATEDIBSECTION | LR_LOADFROMFILE);		//�̹����� �Ӽ� 

	if (0 == m_hBMP)//�ε����
		assert(nullptr);


	m_hDC = CreateCompatibleDC(CCore::getInst()->GetMainDC());

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hDC, m_hBMP);

	GetObject(m_hBMP, sizeof(BITMAP), &m_bmpInfo);
}

void CTexture::Create(UINT width, UINT height)//�ҷ����� �ʰ� ����ִ� texture ����
{
	HDC mainDC = CCore::getInst()->GetMainDC();
	m_hBMP = CreateCompatibleBitmap(mainDC, width, height);
	m_hDC = CreateCompatibleDC(mainDC);

	HBITMAP hOldBMP = (HBITMAP)SelectObject(m_hDC, m_hBMP);
	DeleteObject(hOldBMP);
	GetObject(m_hBMP, sizeof(BITMAP), &m_bmpInfo);
}


int CTexture::GetBmpWidth()
{
	return m_bmpInfo.bmWidth;
}

int CTexture::GetBmpHeight()
{
	return m_bmpInfo.bmHeight;
}

