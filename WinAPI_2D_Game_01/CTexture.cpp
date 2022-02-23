#include "pch.h"
#include "CTexture.h"


CTexture::CTexture()
	:m_hBit(0),
	m_dc(0)
{
}

CTexture::~CTexture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}


void CTexture::Load(const wstring& _strFilePath)
{
	//매개변수로 경로를 받아서 메모리에 올리고 비트맵 ID로 가리켜야한다
	//dc - bitmap을 텍스쳐객체가 알게 해서 동기화
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0,0,LR_CREATEDIBSECTION|LR_LOADFROMFILE);

	// 로딩이 안되었을경우
	assert(m_hBit);

}
