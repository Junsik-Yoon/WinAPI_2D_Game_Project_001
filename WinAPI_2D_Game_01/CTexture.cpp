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
		nullptr,				//hInstance ,nullptr로 두는 이유는 다른 인스턴스에서 따오는게 아니라 파일에서 따오는것이기때문에 null로준다
		strFilePath.c_str(),	//파일의 경로 //c스타일문자열로 바꿔줘야함 string은 c에없음
		IMAGE_BITMAP,			//이미지 타입, 비트맵 이미지로 지정
		0, 0,					//이미지의 xy크기, 0을주면 자동으로 이미지 크기가 설정됨
		LR_CREATEDIBSECTION | LR_LOADFROMFILE);//이미지의 속성 //기본적으로 createdibsection 과 파일에서불러오기의 조합으로 만듬

	if (0 == m_hBMP)//이미지를 load하는데 실패했다면
		assert(nullptr);

	//비트맵을 가지고 BmpInfo를 알아내야함
	//비트맵을 다룰 DC만들기
	m_hDC = CreateCompatibleDC(CCore::getInst()->GetMainDC());

	//비트맵과 DC를 연결
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hDC, m_hBMP);

	//비트맵 info 추출
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

