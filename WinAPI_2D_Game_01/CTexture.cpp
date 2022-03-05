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
		strFilePath.c_str(),						//파일의 경로
		IMAGE_BITMAP,								//이미지 타입
		0, 0,										//이미지의 xy크기, 0==default
		LR_CREATEDIBSECTION | LR_LOADFROMFILE);		//이미지의 속성 

	if (0 == m_hBMP)//로드실패
		assert(nullptr);


	m_hDC = CreateCompatibleDC(CCore::getInst()->GetMainDC());

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hDC, m_hBMP);

	GetObject(m_hBMP, sizeof(BITMAP), &m_bmpInfo);
}




