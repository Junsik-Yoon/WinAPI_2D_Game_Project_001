#include "pch.h"
#include "CPathManager.h"

CPathManager::CPathManager()
{

}
CPathManager::~CPathManager()
{
}

void CPathManager::init()
{
	GetCurrentDirectory(MAXSIZE_PATH,m_szContentPath);//���α׷� ��θ� Ȯ���ϴ� �Լ�
	//���: (���� �ַ�ǰ��) \Output\Debug
	//���: (���� �ַ�ǰ��) \Output\Release
	//����� ������ ����
	int size = wcslen(m_szContentPath);
	for (int i = size - 1; i >= 0; --i)
	{
		if ('\\' == m_szContentPath[i])//�������ð� ���ö����� ���ڸ� �ϳ��� �ڷΰ��� ã�´�
		{
			m_szContentPath[i] = '\0'; //null���ڰ� ������ 
			break;//ã������ break;
		}
	}
	//���:(���� �ַ�� ���)\Output
	//ĳ���͹迭�� stringó�� +������ �Ҽ��� �����Ƿ�
	wcscat_s(m_szContentPath, MAXSIZE_PATH, L"\\Release\\content\\");//wchar_t���ڿ��ڿ� ���ڿ��� �ٿ��ִ� �Լ�

}

