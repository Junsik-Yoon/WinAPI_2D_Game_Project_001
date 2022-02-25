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
		nullptr,				//hInstance ,nullptr�� �δ� ������ �ٸ� �ν��Ͻ����� �����°� �ƴ϶� ���Ͽ��� �����°��̱⶧���� null���ش�
		strFilePath.c_str(),	//������ ��� //c��Ÿ�Ϲ��ڿ��� �ٲ������ string�� c������
		IMAGE_BITMAP,			//�̹��� Ÿ��, ��Ʈ�� �̹����� ����
		0, 0,					//�̹����� xyũ��, 0���ָ� �ڵ����� �̹��� ũ�Ⱑ ������
		LR_CREATEDIBSECTION | LR_LOADFROMFILE);//�̹����� �Ӽ� //�⺻������ createdibsection �� ���Ͽ����ҷ������� �������� ����

	if (0 == m_hBMP)//�̹����� load�ϴµ� �����ߴٸ�
		assert(nullptr);

	//��Ʈ���� ������ BmpInfo�� �˾Ƴ�����
	//��Ʈ���� �ٷ� DC�����
	m_hDC = CreateCompatibleDC(CCore::getInst()->GetMainDC());

	//��Ʈ�ʰ� DC�� ����
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hDC, m_hBMP);

	//��Ʈ�� info ����
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

