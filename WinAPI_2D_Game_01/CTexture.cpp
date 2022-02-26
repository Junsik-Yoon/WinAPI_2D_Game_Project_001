#include "pch.h"
#include "CTexture.h"
#include "CCore.h"

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
	
	//파일로부터 로딩한 데이터를 비트맵으로 생성
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0,0,LR_CREATEDIBSECTION|LR_LOADFROMFILE);
	
	// 로딩이 안되었을경우
	assert(m_hBit);

	//비트맵과 연결할 DC도 따로 있어야 함
	m_dc = CreateCompatibleDC(CCore::GetInst()->GetMainDC());

	//비트맵과 DC 연결
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hPrevBit);

	//가로 세로 길이를 알아내야 함
	//비트맵 정보
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
	



}
