#include "pch.h"
#include "CPathManager.h"
#include "CCore.h"

CPathManager::CPathManager()
	:m_szContentPath{}
{

}
CPathManager::~CPathManager()
{

}

void CPathManager::init()
{
	//����� ���α׷��� ��ġ -> ������丮�� �޾ƿ� �� ����
	GetCurrentDirectory(255, m_szContentPath); //���� ��ΰ� ä����
	
	int iLen = wcslen(m_szContentPath);

	//���������� �� ��
	for (int i = iLen - 1/*�������ִ����-1����*/; 0<=i; --i)
	{
		if ('\\' == m_szContentPath[i]) // \\���й��ڸ� �߰��ϸ�
		{
			m_szContentPath[i] = '\0'; //null���ڸ� �־ �����ش�
			break;
		}
	}

	wcscat_s(m_szContentPath, 255, L"\\bin\\content\\");//���ڸ� �̾���̴� �Լ�

	//+ �ش�����\\�����س������ҽ�����\\
	
	//   abc\\abc\\abc\\abc
	//-> abc\\abd\\abd\0abc

											   
SetWindowText(hWnd, m_szContentPath);//â���� Ȯ���ϵ��� �ӽ÷�

}
