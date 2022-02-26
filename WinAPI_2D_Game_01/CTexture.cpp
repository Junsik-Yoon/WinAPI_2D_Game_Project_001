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
	//�Ű������� ��θ� �޾Ƽ� �޸𸮿� �ø��� ��Ʈ�� ID�� �����Ѿ��Ѵ�
	//dc - bitmap�� �ؽ��İ�ü�� �˰� �ؼ� ����ȭ
	
	//���Ϸκ��� �ε��� �����͸� ��Ʈ������ ����
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0,0,LR_CREATEDIBSECTION|LR_LOADFROMFILE);
	
	// �ε��� �ȵǾ������
	assert(m_hBit);

	//��Ʈ�ʰ� ������ DC�� ���� �־�� ��
	m_dc = CreateCompatibleDC(CCore::GetInst()->GetMainDC());

	//��Ʈ�ʰ� DC ����
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hPrevBit);

	//���� ���� ���̸� �˾Ƴ��� ��
	//��Ʈ�� ����
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
	



}
